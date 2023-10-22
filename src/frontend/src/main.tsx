import React from 'react';
import ReactDOM from 'react-dom/client';
import App from './App.js';
import './index.css';
import "./css/style.css";
import "./css/style.scss";
import "./css/responsive.css";
// Bootstrap CSS
import "bootstrap/dist/css/bootstrap.min.css";
// Bootstrap Bundle JS
import "bootstrap/dist/js/bootstrap.bundle.min";
import {SocketProvider} from './contexts';

ReactDOM.createRoot(document.getElementById('root')!).render(
  <React.StrictMode>
    <SocketProvider>
      <App />
    </SocketProvider>
  </React.StrictMode>
)
