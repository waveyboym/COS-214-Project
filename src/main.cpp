/**
*@file main.cpp
*@class none
*@author Michael
*@brief entry point of application
*/

//every file that you want compiled must be included in this main file
//if the another file is dependent on that file, it should go above that file's include command
#include <thread>
#include "backend/color/color.cpp"
#include "App/Application.cpp"

/**
*@brief entry point of application
*/
int main(){
    Application app; //set up application
    app.initApp(); //initialise app
    std::thread runnable_app_func(&Application::progressForward, &app);
    app.runApp(); //run app
    runnable_app_func.join();
    return EXIT_SUCCESS;
}
