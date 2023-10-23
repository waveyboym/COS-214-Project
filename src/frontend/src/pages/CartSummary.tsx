// CartSummary.tsx or CartSummary.jsx

import React, { useState } from 'react';
import Modal from 'react-modal';
import { Link, Route } from 'react-router-dom';
import { hero_bg } from '../assets';
import TrackingPage from './TrackingPage';

interface CartSummaryProps {
  cartItems: {
    name: string;
    price: number;
    description: string;
    img: string;
  }[];
}

const CartSummary: React.FC<CartSummaryProps> = ({ cartItems }) => {
  const [isModalOpen, setIsModalOpen] = useState(false);
  const [foodProcessingTime, setFoodProcessingTime] = useState(0);
  const [waiterName, setWaiterName] = useState('');
  const [rating, setRating] = useState(0);

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
                {cartItems.map((item, index) => (
                  <div key={index} className="col-sm-6 col-lg-4 all">
                    <div className="box">
                      <div>
                        <div className="img-box">
                          <img src={item.img} alt="" />
                        </div>
                        <div className="detail-box">
                          <h5>{item.name}</h5>
                          <p>{item.description}</p>
                          <div className="options">
                            <h6>{item.price}</h6>
                          </div>
                        </div>
                      </div>
                    </div>
                  </div>
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

        <footer className="footer_section">
          <div className="container">
            <div className="row">
              <div className="col-md-4 footer-col">
                <div className="footer_contact">
                  <h4>
                    Contact Us
                  </h4>
                  <div className="contact_link_box">
                    <a href="">
                      <i className="fa fa-map-marker" aria-hidden="true"></i>
                      <span>
                        Location
                      </span>
                    </a>
                    <a href="">
                      <i className="fa fa-phone" aria-hidden="true"></i>
                      <span>
                        Call +01 1234567890
                      </span>
                    </a>
                    <a href="">
                      <i className="fa fa-envelope" aria-hidden="true"></i>
                      <span>
                        demo@gmail.com
                      </span>
                    </a>
                  </div>
                </div>
              </div>
              <div className="col-md-4 footer-col">
                <div className="footer_detail">
                  <a href="" className="footer-logo">
                    Everest
                  </a>
                  <p>
                    Everything we do is inspired by our enduring mission:
                    <i>
                      "Prepare for a food experience that will leave you craving for more!"
                    </i>
                  </p>
                  <div className="footer_social">
                    <a href="">
                      <i className="fa fa-facebook" aria-hidden="true"></i>
                    </a>
                    <a href="">
                      <i className="fa fa-twitter" aria-hidden="true"></i>
                    </a>
                    <a href="">
                      <i className="fa fa-linkedin" aria-hidden="true"></i>
                    </a>
                    <a href="">
                      <i className="fa fa-instagram" aria-hidden="true"></i>
                    </a>
                    <a href="">
                      <i className="fa fa-pinterest" aria-hidden="true"></i>
                    </a>
                  </div>
                </div>
              </div>
              <div className="col-md-4 footer-col">
                <h4>
                  Opening Hours
                </h4>
                <p>
                  Everyday
                </p>
                <p>
                  10.00 Am -10.00 Pm
                </p>
              </div>
            </div>
            <div className="footer-info">
              <p>
                &copy; <span id="displayYear"></span> All Rights Reserved By Everest
              </p>
            </div>
          </div>
        </footer>
      </div >
    </div >
  );
};

export default CartSummary;
