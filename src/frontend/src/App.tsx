/**
*@file App.tsx
*@function App
*@author Michael, Carey
*@brief presents the frontend gui and communicates with the backend
*/
import React from 'react';
import { BrowserRouter as Router, Route, Routes } from 'react-router-dom';

// Import your components
import { Home, SplashPage, CartSummary, TrackingPage, Menu } from './pages';
import './fonts/fontawesome-webfont.ttf';
import './fonts/fontawesome-webfont.woff';
import './fonts/fontawesome-webfont.woff2';

const App: React.FC = () => {
    return (
        <Router>
          <Routes>
            <Route path="/" element={<SplashPage />} />
            <Route path="/home" element={<Home />} />
            <Route path="/menu" element={<Menu />} />
            <Route path="/cart-summary" element={<CartSummary/>} />
            <Route path="/tracking" element={<TrackingPage/>} />
          </Routes>
        </Router>
      );
    };
    
    export default App;