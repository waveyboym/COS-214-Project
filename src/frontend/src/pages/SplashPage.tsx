import { Link } from 'react-router-dom';
import { useNavigate } from "react-router-dom";
import { useSocket } from '../contexts';
import { useApiKeyStore } from '../stateStore';


const SplashPage = () => {

    const socket: WebSocket | null = useSocket();
    const navigate = useNavigate();
    const { apikey, setApiKey } = useApiKeyStore((state) => { return { apikey: state.apikey, setApiKey: state.setApiKey }; });

    socket!.onmessage = function(event){
        //this is a template for processing messages sent to the frontend from the backend
        const message = JSON.parse(event.data);

        if(message.status === "success" && message.message === "create_token"){
          setApiKey(message.token);
        }
        else if(message.status === "success" && message.player === "customer"){
          navigate("/home");
        }
        else if(message.status === "success" && message.player === "manager"){
          navigate("/admin");
        }
        else{
          console.log(message);
        }
    }

    const sendMessage = function(player_type: string) {
        const req: string = JSON.stringify({token: apikey, player: player_type, command: "add_token"});
        socket!.send(req);
    }

    return (
        <div className="hero_area">
                  <div className="bg-box">
                    <img src="https://img.freepik.com/fotos-premium/eine-pizza-mit-einem-fehlenden-stueck-und-dem-wort-pizza-darauf_572536-220.jpg?w=1060" alt="" />
                  </div>
                  <header className="header_section">
                    <div className="container">
                      <nav className="navbar navbar-expand-lg custom_nav-container">
                      <Link className="navbar-brand" to="/menu"><span>Everest</span></Link>
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
                                      <a className="btn-box col-lg-5 mr-4" onClick={() => sendMessage("customer")}>Play as Customer</a>
                                      <div className="col-lg-1"/>
                                      <a className="btn-box col-lg-5" onClick={() => sendMessage("manager")}>Play as Manager</a>
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
    )
}

export default SplashPage