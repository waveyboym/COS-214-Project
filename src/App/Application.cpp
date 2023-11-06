#include "Application.hpp" //don't try to sort out this squiggly, if it's red, leave it!

bool Application::existingToken(std::list<std::string> linked_list, std::string token){
    std::list<std::string>::iterator it = std::find(linked_list.begin(), linked_list.end(), token);

    if(it != linked_list.end()){
        return true;
    }
    else{
        return false;
    }
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

std::string Application::insertClient(crow::websocket::connection* client){
    std::string id = "";
    
    while(true){
        id = this->generateUUID();
        if(!this->connected_clients.contains(id)){
            this->connected_clients[id] = client;
            break;
        }
    }

    return id;
}

bool Application::removeClientFromListAndRestaurant(bool is_a_manager, std::string client_uuid){
    if(is_a_manager){
        std::list<std::string>::iterator it = std::find(this->connected_managers.begin(), this->connected_managers.end(), client_uuid);

        if(it != this->connected_managers.end()){
            this->connected_managers.erase(it);
            if(this->connected_managers_table.contains((*it))){
                this->connected_managers_table.erase((*it));
            }
            return true;
        }
        else{
            return false;
        }
    }
    else{
        std::list<std::string>::iterator it = std::find(this->connected_customers.begin(), this->connected_customers.end(), client_uuid);

        if(it != this->connected_customers.end()){
            this->connected_customers.erase(it);
            json req_obj = json::parse(
            "{"
                "\"token\":\""+ client_uuid +"\""
            "}");
            this->restaurant->FRONTEND_processCustomerRestaurantExit(req_obj);
            return true;
        }
        else{
            return false;
        }
    }
}

bool Application::removeClient(crow::websocket::connection* client){
    std::map<std::string, crow::websocket::connection*>::iterator it = this->connected_clients.begin(); 

    while (it != this->connected_clients.end() && it->second != client) { 
        it++; 
    } 

    if(it != this->connected_clients.end()){
        if(this->existingToken(this->connected_managers, it->first)){
            this->removeClientFromListAndRestaurant(true, it->first);
        }
        else{
            this->removeClientFromListAndRestaurant(false, it->first);
        }
        this->connected_clients.erase(it);
        return true;
    }
    else{
        return false;
    }
}

void Application::messageManagers(){
    //mutex locking here to prevent multiple threads from trying to do some deletions or insertions
    std::lock_guard<std::mutex> lock(this->mtx);
    for(std::list<std::string>::iterator it = this->connected_managers.begin(); it != this->connected_managers.end(); ++it){
        if(this->connected_clients.contains((*it)) && this->connected_managers_table.contains((*it))){
            json req_obj = json::parse(
            "{"
                "\"table_type\":\""+ this->connected_managers_table[(*it)] +"\""
            "}");
            this->connected_clients[(*it)]->send_text(this->restaurant->FRONTEND_processManagerGetAll(req_obj));
        }
    }
}

void Application::updateRestaurant(){
    //mutex locking here to prevent multiple threads from trying to do some deletions or insertions
    std::lock_guard<std::mutex> lock(this->mtx);

    if(this->restaurant == nullptr){
        this->restaurant = Restaurant::instance();
    }

    this->restaurant->progressByOneStep();
}

void Application::initApp()
{
    //init important data here
    this->pause_app_execution = false;
    this->quit_app = false;
    if(this->restaurant == nullptr){
        this->restaurant = Restaurant::instance();
    }
}

void Application::runApp()
{
    CROW_ROUTE(this->app, "/")
        .websocket()
        .onopen([&](crow::websocket::connection& conn){
                CROW_LOG_INFO << color::format_colour::make_colour(color::GREEN) << "new websocket connection" << color::format_colour::make_colour(color::DEFAULT);
                
                //mutex locking here to prevent multiple client connections from trying to add at the same time
                std::lock_guard<std::mutex> lock(this->mtx);
                std::string id = this->insertClient(&conn);
                conn.send_text("{\"status\":\"success\", \"message\":\"create_token\", \"token\":\"" + id + "\"}");
                //release lock
                })
        .onclose([&](crow::websocket::connection& conn, const std::string& reason){
                CROW_LOG_INFO << color::format_colour::make_colour(color::RED) << "websocket connection closed: " << reason << color::format_colour::make_colour(color::DEFAULT);
                
                //mutex locking here to prevent multiple client connections from trying to erase at the same time
                std::lock_guard<std::mutex> lock(this->mtx);
                bool remove_status = this->removeClient(&conn);

                if(remove_status){
                    CROW_LOG_INFO << color::format_colour::make_colour(color::GREEN) << "successfully removed client" << color::format_colour::make_colour(color::DEFAULT);
                }
                else{
                    CROW_LOG_INFO << color::format_colour::make_colour(color::RED) << "failed to remove client" << color::format_colour::make_colour(color::DEFAULT);
                }
                //release lock
                })
        .onmessage([&](crow::websocket::connection& conn, const std::string& data, bool is_binary){
                    std::cout << color::format_colour::make_colour(color::BLUE) << "✔ Received message" << color::format_colour::make_colour(color::DEFAULT) << std::endl;
                    
                    this->pause_app_execution = true;

                    if (is_binary){
                        //mutex locking here to prevent multiple client connections from trying to erase at the same time
                        std::lock_guard<std::mutex> lock(this->mtx);
                        //pause game execution
                        conn.send_binary(data);
                        //release lock
                    }
                    else{
                        //mutex locking here to prevent multiple client connections from trying to erase at the same time
                        std::lock_guard<std::mutex> lock(this->mtx);
                        std::string res = this->processFrontendRequest(data);
                        conn.send_text(res);
                        //release lock
                        std::cout << color::format_colour::make_colour(color::BLUE) <<  "✔ Sent back response" << color::format_colour::make_colour(color::DEFAULT) << std::endl;
                    }

                    this->pause_app_execution = false;
                });

    this->app.port(18080)
        //.multithreaded() //if you use all threads, none might be left to execute the game hence why we commented this out
        .run();
    
    this->quit_app = true;
}

void Application::progressForward()
{
    if(this->restaurant == nullptr){
        this->restaurant = Restaurant::instance();
    }

    std::chrono::time_point<std::chrono::system_clock> start, end;
    end, start = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;

    while(!this->quit_app){
        while(elapsed_seconds.count() < 5){
            end = std::chrono::system_clock::now();
            elapsed_seconds = end - start;
        }

        while(this->pause_app_execution){ 
            std::this_thread::yield(); //do not modify 
        }

        std::cout << "[DEBUG] ticked forward once in progressForward " << std::endl;
        //do processing here
        //send message out to all managers
        this->updateRestaurant();
        this->messageManagers();
        
        end, start = std::chrono::system_clock::now();
        elapsed_seconds = end - start;

        while(this->pause_app_execution){ 
            std::this_thread::yield(); //do not modify 
        }
    }
}

std::string Application::processFrontendRequest(std::string req)
{
    //expected req format
    json req_obj = json::parse(req);

    if(!req_obj.contains("token") || !req_obj.contains("player") || !req_obj.contains("command")){
        std::cout << color::format_colour::make_colour(color::RED) << "✗ missing player, token or command request in json object " << color::format_colour::make_colour(color::DEFAULT) << std::endl;
        return "{\"status\":\"error\", \"message\":\"missing player, token or command request in json object\"}";
    }
    else if(req_obj["player"] == "customer"){
        return this->processCustomerRequest(req_obj);
    }
    else if(req_obj["player"] == "manager"){
        return this->processManagerRequest(req_obj);
    }
    else{
        std::cout << color::format_colour::make_colour(color::RED) << "✗ " << req_obj["player"] << " is not a valid player " << color::format_colour::make_colour(color::DEFAULT) << std::endl;
        return "{\"status\":\"error\", \"message\":\"invalid player found\"}";
    }
}

std::string Application::processCustomerRequest(json req_obj)
{
    //check if this client is connected to us
    if(!this->connected_clients.contains(req_obj["token"])){
        std::cout << color::format_colour::make_colour(color::RED) << "✗ " << req_obj["token"] << " token does not exist in connected client tokens" << color::format_colour::make_colour(color::DEFAULT) << std::endl;
        return "{\"status\":\"error\",\"player\":\"customer\",\"message\":\"token does not exist in connected client tokens\"}";
    }

    //check if a manager is trying to play as a customer
    if(this->existingToken(this->connected_managers, req_obj["token"])){
        std::cout << color::format_colour::make_colour(color::RED) << "✗ " << req_obj["token"] << " token is already a manager" << color::format_colour::make_colour(color::DEFAULT) << std::endl;
        return "{\"status\":\"error\",\"player\":\"customer\",\"message\":\"token is already a manager\"}";
    }

    //add their token
    if(req_obj["command"] == "add_token"){
        this->connected_customers.push_back(req_obj["token"]);
        return this->restaurant->FRONTEND_processCustomerRestaurantEntry(req_obj);
    }

    //check that their token exists in customer list
    if(!this->existingToken(this->connected_customers, req_obj["token"])){
        std::cout << color::format_colour::make_colour(color::RED) << "✗ " << req_obj["token"] << " token does not exist in connected customer tokens" << color::format_colour::make_colour(color::DEFAULT) << std::endl;
        return "{\"status\":\"error\",\"player\":\"customer\",\"message\":\"token does not exist in connected customer tokens\"}";
    }

    if(req_obj["command"] == "seat_request" && req_obj.contains("message") && req_obj["message"] == "seat"){
        return this->restaurant->FRONTEND_processCustomerRequestSeat(req_obj);
    }
    else if(req_obj["command"] == "seat_request" && req_obj.contains("message") && req_obj["message"] == "unseat"){
        return this->restaurant->FRONTEND_processCustomerRequestUnSeat(req_obj);
    }
    else if(req_obj["command"] == "create_order" && req_obj.contains("order")){
        return this->restaurant->FRONTEND_processCustomerOrder(req_obj);
    }
    else if(req_obj["command"] == "change_emotional_state" && req_obj.contains("emotional_state")){
        return this->restaurant->FRONTEND_processCustomersEmotion(req_obj);
    }
    else if(req_obj["command"] == "get_food"){
        return this->restaurant->FRONTEND_processUpdateCheck(req_obj);
    }
    else if(req_obj["command"] == "checkout"){
        return this->restaurant->FRONTEND_processCheckOutCustomer(req_obj);
    }
    else{
        std::cout << color::format_colour::make_colour(color::RED) << "✗ " << req_obj["command"] << " is not a valid command " << color::format_colour::make_colour(color::DEFAULT) << std::endl;
        return "{\"status\":\"error\",\"player\":\"customer\",\"message\":\"invalid command found\"}";
    }
}

std::string Application::processManagerRequest(json req_obj)
{
    //check if this client is connected to us
    if(!this->connected_clients.contains(req_obj["token"])){
        std::cout << color::format_colour::make_colour(color::RED) << "✗ " << req_obj["token"] << " token does not exist in connected client tokens" << color::format_colour::make_colour(color::DEFAULT) << std::endl;
        return "{\"status\":\"error\",\"player\":\"manager\",\"message\":\"token does not exist in connected client tokens\"}";
    }

    //check if a customer is trying to play as a manager
    if(this->existingToken(this->connected_customers, req_obj["token"])){
        std::cout << color::format_colour::make_colour(color::RED) << "✗ " << req_obj["token"] << " token is already a customer" << color::format_colour::make_colour(color::DEFAULT) << std::endl;
        return "{\"status\":\"error\",\"player\":\"manager\",\"message\":\"token is already a customer\"}";
    }

    //add their token
    if(req_obj["command"] == "add_token"){
        this->connected_managers.push_back(req_obj["token"]);
        std::string id = req_obj["token"];
        this->connected_managers_table[id] = "waiters";
        return "{\"status\":\"success\",\"player\":\"manager\",\"message\":\"successfully added manager token\"}";
    }

    //check that their token exists in manager list
    std::string id = req_obj["token"];
    if(!this->existingToken(this->connected_managers, req_obj["token"]) && !this->connected_managers_table.contains((id))){
        std::cout << color::format_colour::make_colour(color::RED) << "✗ " << req_obj["token"] << " token does not exist in connected managers tokens" << color::format_colour::make_colour(color::DEFAULT) << std::endl;
        return "{\"status\":\"error\",\"player\":\"manager\",\"message\":\"token does not exist in connected managers tokens\"}";
    }
    
    if(req_obj["command"] == "get_all" && req_obj.contains("table_type")){
        return this->restaurant->FRONTEND_processManagerGetAll(req_obj);
    }
    else if(req_obj["command"] == "update_table" && req_obj.contains("table_type")){
        std::string table_type = req_obj["table_type"];
        this->connected_managers_table[id] = table_type;
        return this->restaurant->FRONTEND_processManagerGetTable(req_obj);
    }
    else{
        std::cout << color::format_colour::make_colour(color::RED) << "✗ " << req_obj["command"] << " is not a valid command " << color::format_colour::make_colour(color::DEFAULT) << std::endl;
        return "{\"status\":\"error\", \"message\":\"invalid command found\"}";
    }
}
