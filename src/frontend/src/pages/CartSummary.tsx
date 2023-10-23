// CartSummary.tsx or CartSummary.jsx

import { useState } from 'react';
import Modal from 'react-modal';
import { Link, Route } from 'react-router-dom';
import TrackingPage from './TrackingPage';
import { CartObject, Footer } from '../components';
import { useCartStore } from '../stateStore';
import { Navbar } from '../components';
import { hero_bg } from '../assets';

const CartSummary = () => {
  const [isModalOpen, setIsModalOpen] = useState(false);
  const [foodProcessingTime, setFoodProcessingTime] = useState(0);
  const [waiterName, setWaiterName] = useState('');
  const [rating, setRating] = useState(0);
  const { cartItems } = useCartStore((state) => { return { cartItems: state.cartItems }; });
  const [totalAmount, setTotalAmount] = useState(cartItems.reduce((acc, item) => acc + item.price, 0));
  const [selectedItems, setSelectedItems] = useState(cartItems);


  const openModal = () => {
    setIsModalOpen(true);
  };

  // Handle user input for rating
  const handleRatingChange = (e: { target: { value: string; }; }) => {
    const userRating = parseInt(e.target.value, 10);
    setRating(userRating);
  };

  const closeModal = () => {
    setIsModalOpen(false);
  };
  const handleCheckout = async () => {
    // Simulate food processing time (in seconds)
    const processingTime = 20; // Adjust this value as needed
    setFoodProcessingTime(processingTime);

    // Assign a waiter (replace with actual logic)
    const assignedWaiter = 'John Doe'; // Replace with actual waiter assignment logic
    setWaiterName(assignedWaiter);

    try {
      // Send the order to your backend for processing
      const response = await fetch('/api/checkout', {
        method: 'POST',
        headers: {
          'Content-Type': 'application/json',
        },
        body: JSON.stringify(cartItems),
      });

      if (response.ok) {
        const result = await response.json();
        // Handle the response from your backend
        // For example, set foodProcessingTime and waiterName based on the response

        // Redirect the user to the tracking page
        // You can use React Router or other routing mechanisms to do this
      } else {
        // Handle errors or display an error message to the user
      }
    } catch (error) {
      console.error('Error during checkout:', error);
      // Handle errors or display an error message to the user
    }
  };


  // In your routing setup
  <Route path="/tracking" element={<TrackingPage foodProcessingTime={foodProcessingTime} waiterName={waiterName} orderStatus={''} />} />

  function handleRemoveItem(id: number): void {
    //remove the item from the selected items
    const newSelectedItems = selectedItems.filter((item) => item.id !== id);
    setSelectedItems(newSelectedItems);


    //remove the total amount of the item from the total amount
    const itemToRemove = selectedItems.find((item) => item.id === id);
    if (itemToRemove) {
      setTotalAmount(totalAmount - itemToRemove.price);
    }

  }

  return (
    <div className="sub_page">
      <div className="hero_area">
        <div className="bg-box">
          <img src={hero_bg} alt="" />
        </div>
        <Navbar route={"Menu"} />
      </div>
      <section className="food_section layout_padding">
        <div className="container">
          <div className="heading_container heading_center">
            <h2>Your Cart Summary</h2>
          </div>
          <div className="filters-content">
            <div className="row grid">
              {selectedItems.map((item) => (
                <div key={item.id} className="col-sm-6 col-lg-4 all">
                  <div className="box">
                    <div>
                      <div className="img-box">
                        <img src={item.img} alt="" />
                      </div>
                      <div className="detail-box">
                        <h5>{item.name}</h5>
                        <p>{item.description}</p>
                        <div className="options">
                          <h6>R{item.price}.00</h6>
                          <button onClick={() => handleRemoveItem(item.id)}>Remove</button>
                        </div>
                      </div>
                    </div>
                  </div>
                </div>
              ))}
            </div>
          </div>
          {/* Checkout button */}
          <div className="total-amount">Total: ${totalAmount}.00</div>
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
  );
};

export default CartSummary;
