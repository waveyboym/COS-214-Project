/**
*@file main.cpp
*@class none
*@author Michael
*@brief entry point of application
*/

#include "backend/App/Application.cpp"

/**
*@brief entry point of application
*/
int main(){
    Application app;
    app.initApp();
    app.runApp();
}