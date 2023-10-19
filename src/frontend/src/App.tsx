/**
*@file main.js
*@class main
*@author Michael
*@brief presents the frontend gui and communicates with the backend
*/

import { useState } from 'react';
import reactLogo from './assets/react.svg';
import viteLogo from '/vite.svg';
import './App.css';

const socket = new WebSocket("ws://127.0.0.1:18080");

function App() {
    const [message, setMessage] = useState<string>("no message has been received yet");

    socket.onmessage = function(event){
        //this is a template for processing messages sent to the frontend from the backend
        const json : {message: string} = JSON.parse(event.data);
        setMessage(json.message);
    }

    const sendMessage = function() {
        //this is a template for sending messages to the backend,
        // please feel free to modify it or build on top of it
        const json = { "message": "hello c++ from javascript"};
        socket.send(JSON.stringify(json));
    }

    return (
        <div>
            <div>
                <a href="https://vitejs.dev" target="_blank">
                <img src={viteLogo} className="logo" alt="Vite logo" />
                </a>
                <a href="https://react.dev" target="_blank">
                <img src={reactLogo} className="logo react" alt="React logo" />
                </a>
            </div>
            <h1>Vite + React</h1>
            <div className="card">
                <button onClick={sendMessage}>
                message from backend {message}
                </button>
                <p>
                Edit <code>src/App.tsx</code> and save to test HMR or click on the button above to send and receive a message from the backend
                </p>
            </div>
            <p className="read-the-docs">
                Click on the Vite and React logos to learn more
            </p>
        </div>
    )
}

export default App
