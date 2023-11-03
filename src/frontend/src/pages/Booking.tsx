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
import { faSearch, faShoppingCart, faUser } from "@fortawesome/free-solid-svg-icons";
import { FontAwesomeIcon } from "@fortawesome/react-fontawesome";
import { useCartStore } from "../stateStore";

const Booking = (props: any) => {
  const [bookingNumber, setBookingNumber] = useState<undefined | number>(undefined);
  const { cartItems } = useCartStore((state) => {return { cartItems: state.cartItems };});

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
            <Link className="navbar-brand" to="/game">
                <span>Everest</span>
              </Link>
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
                  <Link className="nav-link" to="/home"><span>Home</span></Link>
                  </li>
                  <li className={"nav-item " + (props.route === "Menu" ? "active" : "")}>
                    <Link className="nav-link" to="/menu"><span>Menu</span></Link>
                  </li>
                  <li className={"nav-item " + (props.route === "Booking" ? "active" : "")}>
                    <Link className="nav-link" to="/booking"><span>Booking</span></Link>
                  </li>
                  <li className="nav-item active">
                    <a className="nav-link" href="">
                      Book Table <span className="sr-only">(current)</span>
                    </a>
                  </li>
                </ul>
                <div className="user_option">
                <Link to="/tracking" className="user_link">
                    <FontAwesomeIcon icon={faUser} />
                  </Link>
                  <Link to="/cart-summary" className="cart_link">
                    <FontAwesomeIcon icon={faShoppingCart} />
                    <span className="cart_counter">{cartItems.length}</span>
                  </Link>

                  <form className="form-inline">
                    <button
                      className="btn my-2 my-sm-0 nav_search-btn"
                      type="submit"
                    >
                      <FontAwesomeIcon icon={faSearch} />
                    </button>
                  </form>
                  {/* <form className="form-inline">
                    <button className="btn my-2 my-sm-0 nav_search-btn" type="submit">
                      <i className="fa fa-search" aria-hidden="true"></i>
                    </button>
                  </form>
                  <a href="" className="order_online">
                    Order Online
                  </a> */}
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
