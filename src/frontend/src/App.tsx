import React from 'react';
import { BrowserRouter as Router, Route, Routes } from 'react-router-dom';
import Dashboard from './layouts/admin';
// Import your other components
import { Home, SplashPage } from './pages';
import { Menu } from './pages';
import CartSummary from './pages/CartSummary';
import TrackingPage from './pages/TrackingPage';
import './fonts/fontawesome-webfont.ttf';
import './fonts/fontawesome-webfont.woff';
import './fonts/fontawesome-webfont.woff2';
import { ChakraProvider } from '@chakra-ui/react';
// import theme from 'theme/theme';
import { ThemeEditorProvider } from '@hypertheme-editor/chakra-ui';

const App: React.FC = () => {
  return (
    <ChakraProvider>
      <ThemeEditorProvider>
        <Router>
          <Routes>
            <Route path="/" element={<SplashPage />} />
            <Route path="/home" element={<Home />} />
            <Route path="/menu" element={<Menu />} />
            <Route path="/cart-summary" element={<CartSummary />} />
            <Route path="/tracking" element={<TrackingPage />} />
            {/* Add the admin route here */}
            <Route path="/admin" element={<Dashboard />} />
          </Routes>
        </Router>
      </ThemeEditorProvider>

    </ChakraProvider>

  );
};

export default App;
