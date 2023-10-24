/**
*@file main.js
*@class main
*@author Michael, Carey
*@brief presents the frontend gui and communicates with the backend
*/

import { useSocket } from './contexts';
import React from 'react';
import { BrowserRouter as Router, Route, Routes } from 'react-router-dom';

// Import your components
import { Home, SplashPage } from './pages';
import { Menu } from './pages';
import CartSummary from './pages/CartSummary';
import TrackingPage from './pages/TrackingPage';
import './fonts/fontawesome-webfont.ttf';
import './fonts/fontawesome-webfont.woff';
import './fonts/fontawesome-webfont.woff2';

const App: React.FC = () => {
    const socket: WebSocket | null = useSocket();

    socket!.onmessage = function(event){
        //this is a template for processing messages sent to the frontend from the backend
        const json : {message: string} = JSON.parse(event.data);
        //setMessage(json.message);
    }

    const sendMessage = function() {
        //this is a template for sending messages to the backend,
        // please feel free to modify it or build on top of it
        const req: string = "command1=value1";
        socket!.send(req);
    }

    return (
        <Router>
          <Routes>
            <Route path="/" element={<SplashPage />} />
            <Route path="/home" element={<Home />} />
            <Route path="/menu" element={<Menu />} />
            <Route path="/cart-summary" element={<CartSummary/>} />
            <Route path="/tracking" element={<TrackingPage orderStatus={""} />} />
          </Routes>
        </Router>
      );
    };
    
    export default App;