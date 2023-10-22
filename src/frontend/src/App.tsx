/**
*@file main.js
*@class main
*@author Michael
*@brief presents the frontend gui and communicates with the backend
*/

import { useState } from 'react';
import viteLogo from '/vite.svg';
import './App.css';
import { useSocket } from './contexts';
import { reactsvg } from './assets';
import { Button } from './components';
import React from 'react';
import { BrowserRouter as Router, Route, Link, Routes } from 'react-router-dom';
import { RouteProps } from 'react-router-dom'; // Import RouteProps


// Import your components
import Home from './components/Home';

import './css/bootstrap.css';
import './css/style.css';
import './css/responsive.css';
import './css/font-awesome.min.css';
import './css/style.scss';
// import './css/style.css.map';
import './fonts/fontawesome-webfont.ttf';
import './fonts/fontawesome-webfont.woff';
import './fonts/fontawesome-webfont.woff2';
// import './js/bootstrap.js';
// import './js/custom.js';
// import './js/jquery-3.4.1.min.js';

const App: React.FC = () => {
    const [message, setMessage] = useState<string>("no message has been received yet");
    const socket: WebSocket | null = useSocket();

    socket!.onmessage = function(event){
        //this is a template for processing messages sent to the frontend from the backend
        const json : {message: string} = JSON.parse(event.data);
        setMessage(json.message);
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
            <Route path="/" element={
              <>
                <div className="hero_area">
                  <div className="bg-box">
                    <img src="https://img.freepik.com/fotos-premium/eine-pizza-mit-einem-fehlenden-stueck-und-dem-wort-pizza-darauf_572536-220.jpg?w=1060" alt="" />
                  </div>
                  <header className="header_section">
                    <div className="container">
                      <nav className="navbar navbar-expand-lg custom_nav-container">
                        <a className="navbar-brand" href="game.html">
                          <span>
                            Everest
                          </span>
                        </a>
                      </nav>
                    </div>
                  </header>
                  <section className="slider_section">
                    <div id="customCarousel1" className="carousel slide" data-ride="carousel">
                      <div className="carousel-inner">
                        <div className="carousel-item active">
                          <div className="container">
                            <div className="row">
                              <div className="col-md-7 col-lg-6">
                                <div className="detail-box">
                                  <h1>
                                    Run your own restaurant or play as a customer.
                                  </h1>
                                  <div className="row">
                                    <div className="btn-box col-lg-6">
                                      <Link to="/home">Play as Customer</Link>
                                    </div>
                                    <div className="btn-box col-lg-6">
                                      <a href="" className="btn1">
                                        Play as Manager
                                      </a>
                                    </div>
                                  </div>
                                </div>
                              </div>
                            </div>
                          </div>
                        </div>
                      </div>
                    </div>
                  </section>
                </div>
              </>
            } />
            <Route path="/home" element={<Home />} />
          </Routes>
        </Router>
      );
    };
    
    export default App;