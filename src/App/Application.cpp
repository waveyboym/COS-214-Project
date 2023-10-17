#include "Application.hpp"

void Application::initApp()
{
    CROW_ROUTE(this->app, "/")
        .websocket()
        .onopen([&](crow::websocket::connection& conn){
                CROW_LOG_INFO << "new websocket connection";
                })
        .onclose([&](crow::websocket::connection& conn, const std::string& reason){
                CROW_LOG_INFO << "websocket connection closed: " << reason;
                })
        .onmessage([&](crow::websocket::connection& conn, const std::string& data, bool is_binary){
                    std::cout << "Received message: " << data << "\n";
                    if (is_binary){
                        conn.send_binary(data);
                    }
                    else{
                        std::string res = this->processFrontendRequest(data);
                        conn.send_text(res);
                        std::cout << "Sent back response: " << res << "\n";
                    }
                });

    this->app.port(18080)
        .multithreaded()
        .run();
}

void Application::runApp()
{
    
}

std::string Application::processFrontendRequest(std::string req){
    //TODO: add more code
    return "{ \"message\": \"hello javascript from cplusplus\"}";
}