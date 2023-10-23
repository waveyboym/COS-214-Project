// CartSummary.tsx or CartSummary.jsx

import { useState } from 'react';
import Modal from 'react-modal';
import { Link, Route } from 'react-router-dom';
import TrackingPage from './TrackingPage';
import { CartObject, Footer } from '../components';
import { useCartStore } from '../stateStore';


const CartSummary = () => {
  const [isModalOpen, setIsModalOpen] = useState(false);
  const [foodProcessingTime, setFoodProcessingTime] = useState(0);
  const [waiterName, setWaiterName] = useState('');
  const [rating, setRating] = useState(0);
  const { cartItems } = useCartStore((state) => {return { cartItems: state.cartItems };});

  const openModal = () => {
    setIsModalOpen(true);
  };

  const closeModal = () => {
    setIsModalOpen(false);
  };

  const handleCheckout = () => {
    // Simulate food processing time (in seconds)
    const processingTime = 20; // Adjust this value as needed
    setFoodProcessingTime(processingTime);

    // Assign a waiter (replace with actual logic)
    const assignedWaiter = 'John Doe'; // Replace with actual waiter assignment logic
    setWaiterName(assignedWaiter);

    // The order has been checked out, you can handle this in your backend

    // Redirect the user to a tracking page
    // For example, use React Router or another routing mechanism
    // to navigate to the tracking page with foodProcessingTime and waiterName state



  };

  // In your routing setup
<Route path="/tracking" element={<TrackingPage foodProcessingTime={foodProcessingTime} waiterName={waiterName} orderStatus={''} />} />

  return (
    <div className="sub_page">
      <div className="hero_area">
        <div className="bg-box">
          {/* <img src={hero_bg} alt="" /> */}
        </div>
        <header className="header_section">
          <div className="container">
            <nav className="navbar navbar-expand-lg custom_nav-container">
              <Link className="navbar-brand" to="/home">
                Everest
              </Link>
            </nav>
          </div>
        </header>

        <section className="food_section layout_padding">
          <div className="container">
            <div className="heading_container heading_center">
              <h2>Cart Summary</h2>
            </div>
            <div className="filters-content">
              <div className="row grid">
                {cartItems.map((item) => (
                  <CartObject key={item.id} id={item.id} img={item.img} name={item.name} description={item.description} price={item.price} />
                ))}
              </div>
            </div>
            {/* Checkout button */}
            <button onClick={openModal}>Checkout</button>

            <Modal
              isOpen={isModalOpen}
              onRequestClose={closeModal}
              contentLabel="Checkout Modal"
            >
              <h2>Confirm Checkout</h2>
              <p>Are you sure you want to proceed with the checkout?</p>
              <button onClick={handleCheckout}>Yes, Checkout</button>
              <button onClick={closeModal}>Cancel</button>
            </Modal>

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
    </div >
  );
};

export default CartSummary;
