import React, { useState } from 'react';
import { Navbar } from '../components';
import hero_bg from '../assets/hero-bg.jpg';
import o2 from '../assets/o2.jpg';
// Import Swiper styles
import 'swiper/css';
import 'swiper/css/pagination';
// Import Swiper React components
import { Swiper, SwiperSlide } from 'swiper/react';
import { Link } from 'react-router-dom'; // Import Link from react-router-dom

const Booking = () => {
  const [bookingNumber, setBookingNumber] = useState<undefined | number>(undefined);

  // Function to generate a random booking number
  const generateBookingNumber = () => {
    const min = 1;
    const max = 10;
    const randomBookingNumber = Math.floor(Math.random() * (max - min + 1)) + min;
    setBookingNumber(randomBookingNumber);
  };

  return (
    <div className="sub_page">
      <div className="hero_area">
        <div className="bg-box">
          <img src={hero_bg} alt="" />
        </div>
        <header className="header_section">
          <div className="container">
            <nav className="navbar navbar-expand-lg custom_nav-container">
              <a className="navbar-brand" href="game.html">
                <span>Everest</span>
              </a>
              <button
                className="navbar-toggler"
                type="button"
                data-toggle="collapse"
                data-target="#navbarSupportedContent"
                aria-controls="navbarSupportedContent"
                aria-expanded="false"
                aria-label="Toggle navigation"
              >
                <span className=""> </span>
              </button>
              <div className="collapse navbar-collapse" id="navbarSupportedContent">
                <ul className="navbar-nav mx-auto">
                  <li className="nav-item">
                    <a className="nav-link" href="index.html">
                      Home
                    </a>
                  </li>
                  <li className="nav-item">
                    <a className="nav-link" href="menu.html">
                      Menu
                    </a>
                  </li>
                  <li className="nav-item">
                    <a className="nav-link" href="about.html">
                      About
                    </a>
                  </li>
                  <li className="nav-item active">
                    <a className="nav-link" href="book.html">
                      Book Table <span className="sr-only">(current)</span>
                    </a>
                  </li>
                </ul>
                <div className="user_option">
                  <a href="" className="user_link">
                    <i className="fa fa-user" aria-hidden="true"></i>
                  </a>
                  <a className="cart_link" href="#">
                    <svg
                      version="1.1"
                      id="Capa_1"
                      xmlns="http://www.w3.org/2000/svg"
                      xmlnsXlink="http://www.w3.org/1999/xlink"
                      x="0px"
                      y="0px"
                      viewBox="0 0 456.029 456.029"
                    >
                      {/* SVG content */}
                    </svg>
                  </a>
                  <form className="form-inline">
                    <button className="btn my-2 my-sm-0 nav_search-btn" type="submit">
                      <i className="fa fa-search" aria-hidden="true"></i>
                    </button>
                  </form>
                  <a href="" className="order_online">
                    Order Online
                  </a>
                </div>
              </div>
            </nav>
          </div>
        </header>
      </div>
      <section className="book_section layout_padding">
        <div className="container">
          <div className="heading_container">
            <h2>Book A Table</h2>
          </div>
          <div className="row">
            <div className="col-md-12">
              <div className="form_container">
                <form>
                  <div>
                    <input type="text" className="form-control" placeholder="Your Name" />
                  </div>
                  <div>
                    <input type="text" className="form-control" placeholder="Phone Number" />
                  </div>
                  <div>
                    <input type="email" className="form-control" placeholder="Your Email" />
                  </div>
                  <div>
                    <select className="form-control nice-select wide">
                      <option value="" disabled selected>
                        How many persons?
                      </option>
                      <option value="">2</option>
                      <option value="">3</option>
                      <option value="">4</option>
                      <option value="">5</option>
                    </select>
                  </div>
                  <div>
                    <input type="date" className="form-control" />
                  </div>
                  <div className="btn_box">
                    <button onClick={generateBookingNumber}>Book Now</button>
                  </div>
                </form>
              </div>
            </div>
            {/* <div className="col-md-6">
              <div className="map_container">
                <div id="googleMap"></div>
              </div>
            </div> */}
          </div>
        </div>
      </section>
      {bookingNumber && (
        <div className="container">
          <div className="row">
            <div className="col-md-6">
              <div className="booking_number">
                <h3>Your Booking Number:</h3>
                <h2>{bookingNumber}</h2>
              </div>
            </div>
          </div>
        </div>
      )}
    </div>
  );
};

export default Booking;
