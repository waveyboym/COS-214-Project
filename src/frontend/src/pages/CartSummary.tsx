// CartSummary.tsx or CartSummary.jsx

import { useEffect, useState } from 'react';
import Modal from 'react-modal';
import { CartObject, Footer } from '../components';
import { useCartStore, useWaiterStore, usefoodProcessingTimeStore } from '../stateStore';
import { Navbar } from '../components';
import { hero_bg } from '../assets';
import { useSocket } from '../contexts';

const CartSummary = () => {
  const [isModalOpen, setIsModalOpen] = useState(false);
  const {foodProcessingTime, setFoodProcessingTime } = usefoodProcessingTimeStore((state) => { return { foodProcessingTime: state.foodProcessingTime, setFoodProcessingTime: state.setFoodProcessingTime }; });
  const {waiterName, setWaiterName } = useWaiterStore((state) => { return { waiterName: state.waiterName, setWaiterName: state.setWaiterName }; });
  const [rating, setRating] = useState(0);

  const { cartItems, deleteFromCart } = useCartStore((state) => { return { cartItems: state.cartItems, deleteFromCart: state.deleteFromCart }; });
  const [totalAmount, setTotalAmount] = useState(cartItems.reduce((acc, item) => acc + item.price, 0));
  const socket: WebSocket | null = useSocket();

  socket!.onmessage = function(event){
    //the backend responds with the needed data
    const json : {message: string} = JSON.parse(event.data);
    const processingTime = 20; // Adjust this value as needed
    setFoodProcessingTime(processingTime);

    // Assign a waiter (replace with actual logic)
    const assignedWaiter = 'John Doe'; // Replace with actual waiter assignment logic
    setWaiterName(assignedWaiter);
    
    //navigate to the trackingpage here
  }
  
  const sendMessage = function(message: string) {
      //this is a template for sending messages to the backend,
      // please feel free to modify it or build on top of it
      const json = { "player": "customer", "command": "create_order"};
      socket!.send(JSON.stringify(json));
  }

  const openModal = () => { setIsModalOpen(true); };

  const closeModal = () => { setIsModalOpen(false); };

  // Handle user input for rating
  const handleRatingChange = (e: { target: { value: string; }; }) => {
    const userRating = parseInt(e.target.value, 10);
    setRating(userRating);
  };

  const handleCheckout = async () => {
    sendMessage(JSON.stringify(cartItems));
  };


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
        <Navbar route={"CartSummary"} />
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
          <div className="total-amount">Total: ${totalAmount}.00</div>
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
          maybe its waiting for backend idk :)*/}
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
        </div>
      </section>

      <Footer />
    </div >
  );
};

export default CartSummary;
