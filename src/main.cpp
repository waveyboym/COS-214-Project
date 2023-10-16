/**
*@file main.cpp
*@class none
*@author Michael
*@brief entry point of application
*/

#include "App/Application.cpp"

/**
*@brief entry point of application
*/
int main(){
    Application app; //set up application
    app.initApp(); //initialise app
    app.runApp(); //run app
    return 0; //return
}
