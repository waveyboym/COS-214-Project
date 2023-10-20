import { useSocket } from "../contexts";

type ButtonProps = {
    text: string;
}

const Button = (props: ButtonProps) => {

    const socket: WebSocket | null = useSocket();

    const sendMessage = function() {
        //this is a template for sending messages to the backend,
        // please feel free to modify it or build on top of it
        const req: string = "command1=value1";
        socket!.send(req);
    }

    return (
        <button onClick={sendMessage}>message from backend : {props.text}</button>
    )
}

export default Button