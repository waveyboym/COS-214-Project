import { useState, useEffect } from 'react';
import { useApiKeyStore, useSeatedStore } from '../stateStore';
import { hero_bg } from '../assets';
import { EmotionalStateTab, Navbar, TrackingComponent } from '../components';
import { useSocket } from '../contexts';
import PromptModal from './PromptModal';

//when this page loads, it will make a socket request to the backend to get details about it's order(like all details)
const TrackingPage = () => {
  const [orderStatus, setOrderStatus] = useState<string>("not completed");
  const [waitTime, setwaitTime] = useState(0.0);
  const { seated, setSeated } = useSeatedStore((state) => { return { seated: state.seated, setSeated: state.setSeated }; });
  const { apikey } = useApiKeyStore((state) => { return { apikey: state.apikey }; });
  const [showSplashPrompt, setShowSplashPrompt] = useState(false);
  
  const [emotionalState, setEmotionalState] = useState('neutral'); // Define and set emotionalState
  const socket: WebSocket | null = useSocket();

  socket!.onmessage = function(event){
    //the backend responds with the needed data
    const json = JSON.parse(event.data);
    
    //navigate to the tracking - page here
    if(json.status === "success" && json.player === "customer" && json.command === "seat_request"){
      if(json.message === "seated"){
        setSeated(true);
      }
      else{
        setSeated(false);
      }
    }
    else if(json.status === "success" && json.player === "customer" && json.command === "change_emotional_state"){
      setEmotionalState(json.emotional_state);
    }
    else if(json.status === "success" && json.player === "customer" && json.command === "update_check"){
      //setwaitTime(json.waitTime);
      //setOrderStatus(json.orderStatus);
      console.log(json);
    }
    else if(json.status === "success" && json.player === "customer" && json.command === "checkout"){
      setSeated(false);
    }
    else{
      console.log(json);
    }
  }

  const requestSeat = function(setTo: boolean){
    const json = { token: apikey, player: "customer", command: "seat_request", message: (setTo === true ? "seat" : "unseat")};
    socket!.send(JSON.stringify(json));
  }
  
  const updateMe = function(){
    const json = { token: apikey, player: "customer", command: "update_check"};
    socket!.send(JSON.stringify(json));
  }

  const checkMeOut = function(){
    const json = { token: apikey, player: "customer", command: "checkout"};
    socket!.send(JSON.stringify(json));
  }

  const setCustomerEmotionalState = function(newstate: string){
    const json = { token: apikey, player: "customer", command: "change_emotional_state", emotional_state: newstate};
    socket!.send(JSON.stringify(json));
  }

  useEffect(() => {
      const checkUpdate = function(){
          updateMe();
      }
      checkUpdate();
    }, []);


  return (
    <div className="sub_page">
        <div className="hero_area">
          <div className="bg-box">
            <img src={hero_bg} alt="" />
          </div>
          <Navbar route={"Tracking"} is_seated={seated} setIsSeated={requestSeat}/>
        </div>
        <h1 style={{textAlign: "center"}}>Order Tracking</h1>
          <TrackingComponent checkMeOut={checkMeOut} waitTime={waitTime} orderStatus={orderStatus} date={new Date().toString()} checkUpdate={updateMe}/>
        <div style={{height: "20px"}}/>
          
      <EmotionalStateTab emotionalState={emotionalState} setEmotionalState={setCustomerEmotionalState} />
    
      {showSplashPrompt && (
        // Render the modal or pop-up
        <PromptModal onClose={() => setShowSplashPrompt(false)} />
      )}
    </div>
  );
}

/*
*
 * 
 * <div className="col-sm-6 col-lg-4 all fries">
        {foodProcessingTime > 0 ? (
          <div>
            <h2>Assigned Waiter: {waitTime}</h2>
            <h2>Time Remaining: {foodProcessingTime} seconds</h2>

            <h2>Order Status:</h2>
            <div>
              <div className={`status-item ${orderStatus === 'Order Processed' ? 'pulse-animation' : ''}`}>
                Order Processed (Chef received the order)
              </div>
              <div className={`status-item ${orderStatus === 'Order Processing' ? 'pulse-animation' : ''}`}>
                Order Processing (Chefs cooking)
              </div>
              <div className={`status-item ${orderStatus === 'Order Ready' ? 'pulse-animation' : ''}`}>
                Order Ready (Food is ready)
              </div>
              <div className={`status-item ${orderStatus === 'Order Delivered' ? 'pulse-animation' : ''}`}>
                Order Delivered (Waiter delivered the food)
              </div>
              
            </div>
            
          </div>
          
        ) : (
          <div>
            <h2>Waiter time: {waitTime} seconds</h2>
            <h2>Order Status: {orderStatus}</h2>

            {orderStatus === 'Order Delivered' && (
              <button onClick={handleCheckoutClick}>Proceed to Checkout</button>
            )}
          </div>
        )}
      </div>
 */


export default TrackingPage;
