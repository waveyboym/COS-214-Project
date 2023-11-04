import React from 'react';
import { BrowserRouter as Router, Route, Routes } from 'react-router-dom';
import DashboardContainer from './pages/DashboardContainer';
// Import your other components
import { Home, SplashPage } from './pages';
import { Menu } from './pages';
import CartSummary from './pages/CartSummary';
import TrackingPage from './pages/TrackingPage';
import Booking from './pages/Booking';
import TrackingBooking from './pages/TrackingBooking';
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
            <Route path="/cart-summary" element={<CartSummary />} />
            <Route path="/tracking" element={<TrackingPage />} />
            <Route path="/booking" element={<Booking />} />
            <Route path="/trackingbooking" element={<TrackingBooking orderStatus={''} date={''} emotionalState={''} cartName={''} cartImage={''} waiterName={''}/>} />

            {/* Add the admin route here */}
            <Route path="/admin" element={<DashboardContainer />} />
          </Routes>
        </Router>

  );
};

export default App;
