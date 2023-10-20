#include "Application.hpp"

void Application::initApp()
{
    //init important data here
    this->pauseAppExecution = false;
    this->quitApp = false;
}

void Application::runApp()
{
    CROW_ROUTE(this->app, "/")
        .websocket()
        .onopen([&](crow::websocket::connection& conn){
                CROW_LOG_INFO << color::format_colour::make_colour(color::GREEN) << "new websocket connection" << color::format_colour::make_colour(color::DEFAULT);
                
                //mutex locking here to prevent multiple client connections from trying to add at the same time
                std::lock_guard<std::mutex> _(this->mtx);
                this->connected_clients.insert(&conn);
                //release lock
                })
        .onclose([&](crow::websocket::connection& conn, const std::string& reason){
                CROW_LOG_INFO << color::format_colour::make_colour(color::RED) << "websocket connection closed: " << reason << color::format_colour::make_colour(color::DEFAULT);
                
                //mutex locking here to prevent multiple client connections from trying to erase at the same time
                std::lock_guard<std::mutex> _(this->mtx);
                this->connected_clients.erase(&conn);
                //release lock
                })
        .onmessage([&](crow::websocket::connection& /*conn*/, const std::string& data, bool is_binary){
                    std::cout << color::format_colour::make_colour(color::BLUE) << "Received message: " << color::format_colour::make_colour(color::DEFAULT) << data << "\n";
                    
                    this->pauseAppExecution = true;

                    if (is_binary){
                        //mutex locking here to prevent multiple client connections from trying to erase at the same time
                        std::lock_guard<std::mutex> _(this->mtx);
                        //pause game execution
                        for(auto client : this->connected_clients){//send response to all clients connected to our websocket
                            client->send_binary(data);
                        }
                        //release lock
                    }
                    else{
                        std::string res = this->processFrontendRequest(data);
                        //mutex locking here to prevent multiple client connections from trying to erase at the same time
                        std::lock_guard<std::mutex> _(this->mtx);
                        //pause game execution
                        for(auto client : this->connected_clients){//send response to all clients connected to our websocket
                            client->send_text(res);
                        }
                        //release lock
                        std::cout << color::format_colour::make_colour(color::BLUE) <<  "Sent back response: " << color::format_colour::make_colour(color::DEFAULT) << res << "\n";
                    }

                    this->pauseAppExecution = false;
                });

    this->app.port(18080)
        //.multithreaded()
        .run();
    
    this->quitApp = true;
}

void Application::progressForward(){
    //this can be removed if needed
    std::chrono::time_point<std::chrono::system_clock> start, end;
    end, start = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;
    //end of removable code

    while(!this->quitApp){
        //this can be removed if needed
        while(elapsed_seconds.count() < 5){
            end = std::chrono::system_clock::now();
            elapsed_seconds = end - start;
        }

        std::cout << "ticked forward once in progressForward " << std::endl;
        //do processing here
        end, start = std::chrono::system_clock::now();
        elapsed_seconds = end - start;
        //end of removable code

        while (this->pauseAppExecution) { std::this_thread::yield(); } // do not modify
    }
}


std::string Application::processFrontendRequest(std::string req){
    //TODO: add more code
    //ISSUE ID: 1 If you decide to take this issue, please indicate this on the issues tab on github for ISSUE ID: 1

    //expected req format -> command1=value1&command2=value2&command3=value3...&commandn=valuen

    int query_string_iterator = 0;
    std::string res = "{";

    while(query_string_iterator < req.length()){
        std::string command = "";
        while(query_string_iterator < req.length() && req[query_string_iterator] != '='){
            command += req[query_string_iterator];
            ++query_string_iterator;
        }
        
        if(req[query_string_iterator] != '='){
            return "{ \"message\": \"failed to process -> " + req +", because of missing = at index: " + std::to_string(query_string_iterator) + "\"}";
        }
        ++query_string_iterator;
        
        std::string message = "";
        while(query_string_iterator < req.length() && req[query_string_iterator] != '&'){
            message += req[query_string_iterator];
            ++query_string_iterator;
        }
        
        if(req[query_string_iterator] != '&' && query_string_iterator != req.length()){
            return "{ \"message\": \"failed to process -> " + req +", because of missing & at index: " + std::to_string(query_string_iterator) + "\"}";
        }

        ++query_string_iterator;
        if(query_string_iterator < req.length()){//query_string_iterator is req.length() + 1 now
            res += doBackendTask(command, message) + ",";
        }
        else{
            res += doBackendTask(command, message);
        }
    }

    res += "}";

    return res;
}

std::string Application::doBackendTask(std::string command, std::string value){
    return "\"message\":\"you gave me this command -> "+ command +" with this message -> " + value +"\"";
}