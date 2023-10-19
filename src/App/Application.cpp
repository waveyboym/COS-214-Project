#include "Application.hpp"

void Application::initApp()
{
    CROW_ROUTE(this->app, "/")
        .websocket()
        .onopen([&](crow::websocket::connection& conn){
                CROW_LOG_INFO << color::format_colour::make_colour(color::GREEN) << "new websocket connection" << color::format_colour::make_colour(color::DEFAULT);
                })
        .onclose([&](crow::websocket::connection& conn, const std::string& reason){
                CROW_LOG_INFO << color::format_colour::make_colour(color::RED) << "websocket connection closed: " << reason << color::format_colour::make_colour(color::DEFAULT);
                })
        .onmessage([&](crow::websocket::connection& conn, const std::string& data, bool is_binary){
                    std::cout << color::format_colour::make_colour(color::BLUE) << "Received message: " << color::format_colour::make_colour(color::DEFAULT) << data << "\n";
                    if (is_binary){
                        conn.send_binary(data);
                    }
                    else{
                        std::string res = this->processFrontendRequest(data);
                        conn.send_text(res);
                        std::cout << color::format_colour::make_colour(color::BLUE) <<  "Sent back response: " << color::format_colour::make_colour(color::DEFAULT) << res << "\n";
                    }
                });

    this->app.port(18080)
        .multithreaded()
        .run();
}

void Application::runApp()
{
    while(true){
        //poll events in events queue

        //update game/simulation

        //display or send back updated data
    }
}

std::string Application::processFrontendRequest(std::string req){
    //TODO: add more code
    //ISSUE ID: 1 If you decide to take this issue, please indicate this on the issues tab on github for ISSUE ID: 1
    return "{ \"message\": \"hello javascript from cplusplus\"}";
}