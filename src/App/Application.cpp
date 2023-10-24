#include "Application.hpp" //don't try to sort out this squiggly, if it's red, leave it!

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

void Application::progressForward()
{
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

std::string Application::processFrontendRequest(std::string req)
{
    //expected req format
    json req_obj = json::parse(req);

    if(!req_obj.contains("player") || !req_obj.contains("command")){
        std::cout << color::format_colour::make_colour(color::RED) << " missing player or command request in json object " << color::format_colour::make_colour(color::DEFAULT) << std::endl;
        return "{\"message\":\"missing player or command request in json object\"}";
    }
    else if(req_obj["player"] == "customer"){
        return this->processCustomerRequest(req_obj);
    }
    else if(req_obj["player"] == "manager"){
        return this->processManagerRequest(req_obj);
    }
    else{
        std::cout << color::format_colour::make_colour(color::RED) << req_obj["player"] << " is not a valid player " << color::format_colour::make_colour(color::DEFAULT) << std::endl;
        return "{\"message\":\"invalid player found\"}";
    }
}

std::string Application::processCustomerRequest(json req_obj)
{
    //TODO: add more code
    //ISSUE ID: 2 If you decide to take this issue, please indicate this on the issues tab on github for ISSUE ID: 2
    if(req_obj["command"] == "create_order"){
        std::cout << color::format_colour::make_colour(color::GREEN) << " received request successfully " << color::format_colour::make_colour(color::DEFAULT) << std::endl;
        return "{\"message\":\"received request\"}";
    }
    else{
        std::cout << color::format_colour::make_colour(color::RED) << req_obj["command"] << " is not a valid command " << color::format_colour::make_colour(color::DEFAULT) << std::endl;
        return "{\"message\":\"invalid command found\"}";
    }
}

std::string Application::processManagerRequest(json req_obj)
{
    //TODO: add more code
    //ISSUE ID: 3 If you decide to take this issue, please indicate this on the issues tab on github for ISSUE ID: 3
    if(req_obj["command"] == "get_all"){
        std::cout << color::format_colour::make_colour(color::GREEN) << " received request successfully " << color::format_colour::make_colour(color::DEFAULT) << std::endl;
        return "{\"message\":\"received request\"}";
    }
    else{
        std::cout << color::format_colour::make_colour(color::RED) << req_obj["player"] << " is not a valid command " << color::format_colour::make_colour(color::DEFAULT) << std::endl;
        return "{\"message\":\"invalid command found\"}";
    }
}