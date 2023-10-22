import React from 'react';
import ReactDOM from 'react-dom/client';
import App from './App.js';
import './index.css';
import {SocketProvider} from './contexts';

ReactDOM.createRoot(document.getElementById('root')!).render(
  <React.StrictMode>
    <SocketProvider>
      <App />
    </SocketProvider>
  </React.StrictMode>,
)
