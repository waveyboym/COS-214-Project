import { createContext, useContext } from "react";

export const SocketContext = createContext<WebSocket | null>(null);

const SocketProvider = ({ children }: { children: any;}) => {
  const socket: WebSocket = new WebSocket("ws://127.0.0.1:18080");

  return (
    <SocketContext.Provider value={socket}>
      {children}
    </SocketContext.Provider>
  );
}

export const useSocket = () => useContext(SocketContext);

export default SocketProvider;