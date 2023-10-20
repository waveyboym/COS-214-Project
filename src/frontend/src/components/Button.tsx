import { useSocket } from "../contexts";

type ButtonProps = {
    text: string;
}

const Button = (props: ButtonProps) => {

    const socket: WebSocket | null = useSocket();

    const sendMessage = function() {
        //this is a template for sending messages to the backend,
        // please feel free to modify it or build on top of it
        const json : {message: string} = { "message": "hello c++ from javascript"};
        socket!.send(JSON.stringify(json));
    }

    return (
        <button onClick={sendMessage}>message from backend : {props.text}</button>
    )
}

export default Button