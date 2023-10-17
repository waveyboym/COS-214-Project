/**
*@file main.js
*@class main
*@author Michael
*@brief has a set of utility functions that are used for communicating with the backend
*/

// NOTE: avoid using var, use let when you need variables that change, BUT use const as much as possible

const socket = new WebSocket("ws://127.0.0.1:18080");

window.onload = function(){
    //if you want to do some stuff as soon as the page loads, add code here
};

socket.onmessage = function(event){
    //this is a template for processing messages sent to the frontend from the backend
    const json = JSON.parse(event.data);
    console.log(json);
}

const sendMessage = function() {
    //this is a template for sending messages to the backend,
    // please feel free to modify it or build on top of it
    console.log("sending message");
    const json = { "message": "hello cplusplus from javascript"};
    socket.send(JSON.stringify(json));
    console.log("sent message");
}