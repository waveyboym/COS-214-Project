#include "Application.hpp" //don't try to sort out this squiggly, if it's red, leave it!

bool Application::existingToken(std::list<std::string> linked_list, std::string token){
    std::list<std::string>::iterator it = std::find(linked_list.begin(), linked_list.end(), token);

    if(it != linked_list.end()){
        return true;
    }
    else{
        return false;
    }
    return false;
}

std::string Application::generateUUID(){
    std::random_device rd;
    auto seed_data = std::array<int, std::mt19937::state_size> {};
    std::generate(std::begin(seed_data), std::end(seed_data), std::ref(rd));
    std::seed_seq seq(std::begin(seed_data), std::end(seed_data));
    std::mt19937 generator(seq);
    uuids::uuid_random_generator gen{generator};

    uuids::uuid const idUUID = gen();

    std::string id = uuids::to_string(idUUID);

    return id;
}

void Application::initApp()
{
    //init important data here
    this->pause_app_execution = false;
    this->quit_app = false;
}

void Application::runApp()
{
    CROW_ROUTE(this->app, "/")
        .websocket()
        .onopen([&](crow::websocket::connection& conn){
                CROW_LOG_INFO << color::format_colour::make_colour(color::GREEN) << "new websocket connection" << color::format_colour::make_colour(color::DEFAULT);
                
                //mutex locking here to prevent multiple client connections from trying to add at the same time
                std::lock_guard<std::mutex> _(this->mtx);
                std::string id = this->generateUUID();
                this->connected_clients.insert(&conn);
                conn.send_text("{\"status\":\"success\", \"message\":\"create_token\", \"token\":\"" + id + "\"}");
                //release lock
                })
        .onclose([&](crow::websocket::connection& conn, const std::string& reason){
                CROW_LOG_INFO << color::format_colour::make_colour(color::RED) << "websocket connection closed: " << reason << color::format_colour::make_colour(color::DEFAULT);
                
                //mutex locking here to prevent multiple client connections from trying to erase at the same time
                std::lock_guard<std::mutex> _(this->mtx);
                this->connected_clients.erase(&conn);
                //release lock
                })
        .onmessage([&](crow::websocket::connection& conn, const std::string& data, bool is_binary){
                    std::cout << color::format_colour::make_colour(color::BLUE) << "Received message: " << color::format_colour::make_colour(color::DEFAULT) << data << "\n";
                    
                    this->pause_app_execution = true;

                    if (is_binary){
                        //mutex locking here to prevent multiple client connections from trying to erase at the same time
                        std::lock_guard<std::mutex> _(this->mtx);
                        //pause game execution
                        conn.send_binary(data);
                        //release lock
                    }
                    else{
                        std::string res = this->processFrontendRequest(data);
                        //mutex locking here to prevent multiple client connections from trying to erase at the same time
                        std::lock_guard<std::mutex> _(this->mtx);
                        conn.send_text(res);
                        //release lock
                        std::cout << color::format_colour::make_colour(color::BLUE) <<  "Sent back response: " << color::format_colour::make_colour(color::DEFAULT) << res << "\n";
                    }

                    this->pause_app_execution = false;
                });

    this->app.port(18080)
        //.multithreaded()
        .run();
    
    this->quit_app = true;
}

void Application::progressForward()
{
    //this can be removed if needed
    std::chrono::time_point<std::chrono::system_clock> start, end;
    end, start = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;
    //end of removable code

    while(!this->quit_app){
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

        while (this->pause_app_execution) { std::this_thread::yield(); } // do not modify
    }
}

std::string Application::processFrontendRequest(std::string req)
{
    //expected req format
    json req_obj = json::parse(req);

    if(!req_obj.contains("token") || !req_obj.contains("player") || !req_obj.contains("command")){
        std::cout << color::format_colour::make_colour(color::RED) << " missing player, token or command request in json object " << color::format_colour::make_colour(color::DEFAULT) << std::endl;
        return "{\"status\":\"error\", \"message\":\"missing player, token or command request in json object\"}";
    }
    else if(req_obj["player"] == "customer"){
        return this->processCustomerRequest(req_obj);
    }
    else if(req_obj["player"] == "manager"){
        return this->processManagerRequest(req_obj);
    }
    else{
        std::cout << color::format_colour::make_colour(color::RED) << req_obj["player"] << " is not a valid player " << color::format_colour::make_colour(color::DEFAULT) << std::endl;
        return "{\"status\":\"error\", \"message\":\"invalid player found\"}";
    }
}

std::string Application::processCustomerRequest(json req_obj)
{
    //TODO: add more code
    //ISSUE ID: 2 If you decide to take this issue, please indicate this on the issues tab on github for ISSUE ID: 2

    //check if a manager is trying to play as a customer
    if(this->existingToken(this->connected_managers, req_obj["token"])){
        std::cout << color::format_colour::make_colour(color::RED) << req_obj["token"] << " token is already a manager" << color::format_colour::make_colour(color::DEFAULT) << std::endl;
        return "{\"status\":\"error\", \"message\":\"token is already a manager\"}";
    }

    //add their token
    if(req_obj["command"] == "add_token"){
        this->connected_customers.push_back(req_obj["token"]);
        return "{\"status\":\"success\", \"message\":\"successfully added customer token\"}";
    }

    //check that their token exists in customer list
    if(!this->existingToken(this->connected_customers, req_obj["token"])){
        std::cout << color::format_colour::make_colour(color::RED) << req_obj["token"] << " token does not exist in connected customer tokens" << color::format_colour::make_colour(color::DEFAULT) << std::endl;
        return "{\"status\":\"error\", \"message\":\"token does not exist in connected customer tokens\"}";
    }

    if(req_obj["command"] == "create_order"){
        std::cout << color::format_colour::make_colour(color::GREEN) << " received request successfully " << color::format_colour::make_colour(color::DEFAULT) << std::endl;
        return "{\"status\":\"success\", \"message\":\"successfully created order\"}";
    }
    else{
        std::cout << color::format_colour::make_colour(color::RED) << req_obj["command"] << " is not a valid command " << color::format_colour::make_colour(color::DEFAULT) << std::endl;
        return "{\"status\":\"error\", \"message\":\"invalid command found\"}";
    }
}

std::string Application::processManagerRequest(json req_obj)
{
    //TODO: add more code
    //ISSUE ID: 3 If you decide to take this issue, please indicate this on the issues tab on github for ISSUE ID: 3

    //check if a customer is trying to play as a manager
    if(this->existingToken(this->connected_customers, req_obj["token"])){
        std::cout << color::format_colour::make_colour(color::RED) << req_obj["token"] << " token is already a customer" << color::format_colour::make_colour(color::DEFAULT) << std::endl;
        return "{\"status\":\"error\", \"message\":\"token is already a customer\"}";
    }

    //add their token
    if(req_obj["command"] == "add_token"){
        this->connected_managers.push_back(req_obj["token"]);
        return "{\"status\":\"success\", \"message\":\"successfully added manager token\"}";
    }

    //check that their token exists in manager list
    if(!this->existingToken(this->connected_managers, req_obj["token"])){
        std::cout << color::format_colour::make_colour(color::RED) << req_obj["token"] << " token does not exist in connected managers tokens" << color::format_colour::make_colour(color::DEFAULT) << std::endl;
        return "{\"status\":\"error\", \"message\":\"token does not exist in connected managers tokens\"}";
    }
    
    if(req_obj["command"] == "get_all"){
        std::cout << color::format_colour::make_colour(color::GREEN) << " received request successfully " << color::format_colour::make_colour(color::DEFAULT) << std::endl;
        return "{\"status\":\"success\", \"message\":\"successfully got all\"}";
    }
    else{
        std::cout << color::format_colour::make_colour(color::RED) << req_obj["player"] << " is not a valid command " << color::format_colour::make_colour(color::DEFAULT) << std::endl;
        return "{\"status\":\"error\", \"message\":\"invalid command found\"}";
    }
}