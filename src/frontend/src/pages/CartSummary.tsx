// CartSummary.tsx or CartSummary.jsx

import { useEffect, useState } from 'react';
import Modal from 'react-modal';
import { CartObject, Footer } from '../components';
import { useApiKeyStore, useCartStore, useSeatedStore, } from '../stateStore';
import { Navbar } from '../components';
import { hero_bg } from '../assets';
import { useSocket } from '../contexts';
import { useNavigate } from 'react-router-dom';

const CartSummary = () => {
  const [isModalOpen, setIsModalOpen] = useState(false);
  const { cartItems, deleteFromCart } = useCartStore((state) => { return { cartItems: state.cartItems, deleteFromCart: state.deleteFromCart }; });
  const [totalAmount, setTotalAmount] = useState(cartItems.reduce((acc, item) => acc + item.price, 0));
  const { apikey } = useApiKeyStore((state) => { return { apikey: state.apikey }; });
  const { seated, setSeated } = useSeatedStore((state) => { return { seated: state.seated, setSeated: state.setSeated }; });
  const socket: WebSocket | null = useSocket();
  const navigate = useNavigate();

  //const {foodProcessingTime, setFoodProcessingTime } = usefoodProcessingTimeStore((state) => { return { foodProcessingTime: state.foodProcessingTime, setFoodProcessingTime: state.setFoodProcessingTime }; });
  //const {waiterName, setWaiterName } = useWaiterStore((state) => { return { waiterName: state.waiterName, setWaiterName: state.setWaiterName }; });
  //const [rating, setRating] = useState(0);


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
    else if(json.status === "success" && json.player === "customer" && json.command === "checkout"){
      navigate("/tracking");
    }
    else{
      console.log(json);
    }
  }

  const openModal = () => { setIsModalOpen(true); };

  const closeModal = () => { setIsModalOpen(false); };

  const handleCheckout = async () => {
    sendMessage();
  };

  const sendMessage = function() {
    const json = { token: apikey, player: "customer", command: "create_order", order: cartItems};
    socket!.send(JSON.stringify(json));
  }

  const requestSeat = function(setTo: boolean){
    const json = { token: apikey, player: "customer", command: "seat_request", message: (setTo === true ? "seat" : "unseat")};
    socket!.send(JSON.stringify(json));
  }


  // In your routing setup

  function handleRemoveItem(id: number): void {
    //remove the item from the selected items
    deleteFromCart(id);
    setTotalAmount(cartItems.reduce((acc, item) => acc + item.price, 0));
  }

  useEffect(() => {
    const countItems = () =>{
      setTotalAmount(cartItems.reduce((acc, item) => acc + item.price, 0));
    }

    countItems();
  }, [cartItems])
  

  return (
    <div className="sub_page">
      <div className="hero_area">
        <div className="bg-box">
          <img src={hero_bg} alt="" />
        </div>
        <Navbar route={"CartSummary"} is_seated={seated} setIsSeated={requestSeat}/>
      </div>
      <section className="food_section layout_padding">
        <div className="container">
          <div className="heading_container heading_center">
            <h2>Your Cart Summary</h2>
          </div>
          <div className="filters-content">
            <div className="row grid">
              {cartItems.map((item) => (
                <CartObject key={item.id} id={item.id} name={item.name} price={item.price} img={item.img} description={item.description} handleRemoveItem={handleRemoveItem}/>
              ))}
            </div>
          </div>
          {/* Checkout button */}
          <h2 className="total-amount mt-3 mb-3">Total: ${totalAmount}.00</h2>
          <button className="btn my-2 my-sm-0 btn-warning" onClick={openModal}>Checkout</button>

          <Modal
            isOpen={isModalOpen}
            onRequestClose={closeModal}
            contentLabel="Checkout Modal"
          >
            <h2>Confirm Checkout</h2>
            <p>Are you sure you want to proceed with the checkout?</p>
            <button className="btn my-2 my-sm-0 btn-warning" onClick={handleCheckout}>Yes, Checkout</button>
            <button className="btn my-2 my-sm-0 btn-secondary" onClick={closeModal}>Cancel</button>
          </Modal>

          {/* Tracking info NOT WORKING WELL -- NEED TO FIX
          maybe its waiting for backend idk :)


          {foodProcessingTime > 0 && waiterName && (
            <div className="tracking-info">
              <h3>Food Processing Time: {foodProcessingTime} seconds</h3>
              <h3>Assigned Waiter: {waiterName}</h3>
              <p>Rate your experience (1 - 5):</p>
              <input
                type="number"
                min="1"
                max="5"
                value={rating}
                onChange={(e) => setRating(Number(e.target.value))}
              />
            </div>
          )}
          
          */}
          
        </div>
      </section>

      <Footer />
    </div >
  );
};

export default CartSummary;
