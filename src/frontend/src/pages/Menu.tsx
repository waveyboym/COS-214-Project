import React, { useState } from 'react';
import { Link } from 'react-router-dom';


//import lineicons


//import pictures
import { f1 } from '../assets';
import { f2 } from '../assets';
import { f3 } from '../assets';
import { f4 } from '../assets';
import { f5 } from '../assets';
import { f9 } from '../assets';
import { hero_bg } from '../assets';

const Menu: React.FC = () => {
  interface CartItem {
    id: number;
    name: string;
    price: number;
    img: string;
    // Add other properties as needed
  }

  const [cartItems, setCartItems] = useState<CartItem[]>([]); // Specify the type as CartItem[]

  const addToCart = (item: CartItem) => {
    setCartItems([...cartItems, item]);
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
                <ul className="navbar-nav  mx-auto">
                  <li className="nav-item">
                    <Link className="nav-link" to="/home"><span>Home</span></Link>
                  </li>
                  <li className="nav-item active">
                    <Link className="nav-link" to="/menu"><span>Menu</span></Link>
                  </li>
                  <li className="nav-item">
                    <Link className="nav-link" to="/about"><span>About</span></Link>
                  </li>
                  <li className="nav-item">
                    <Link className="nav-link" to="/book"><span>Book</span></Link>
                  </li>
                </ul>
                <div className="user_option">
                  <a href="" className="user_link">
                    <i className="fa fa-user" aria-hidden="true"></i>
                  </a>
                  <Link to="/cart-summary" className="cart_link">
                    <i className="lni lni-cart" style={{ color: 'aliceblue' }}></i>
                    <span className="cart_counter">{cartItems.length}</span>
                  </Link>

                  <form className="form-inline">
                    <button
                      className="btn my-2 my-sm-0 nav_search-btn"
                      type="submit"
                    >
                      <i className="fa fa-search" aria-hidden="true"></i>
                    </button>
                  </form>
                  <Link className="order_online" to='/menu'><span>Order Online</span></Link>
                </div>
              </div>
            </nav>
          </div>
        </header>
      </div>
      <section className="food_section layout_padding">
        <div className="container">
          <div className="heading_container heading_center">
            <h2>Our Menu</h2>
          </div>
          <ul className="filters_menu">
            <li className="active" data-filter="*">
              All
            </li>
            <li data-filter=".burger">Burger</li>
            <li data-filter=".pizza">Pizza</li>
            <li data-filter=".pasta">Pasta</li>
            <li data-filter=".fries">Fries</li>
          </ul>
          <div className="filters-content">
            <div className="row grid">
              <div className="col-sm-6 col-lg-4 all pizza">
                <div className="box">
                  <div>
                    <div className="img-box">
                      <img src={f1} alt="" />
                    </div>
                    <div className="detail-box">
                      <h5>Delicious Pizza</h5>
                      <p>
                        Enjoy our delicious pizza with a variety of toppings
                        to choose from!
                      </p>
                      <div className="options">
                        <h6>R20</h6>
                        <a
                          href="#"
                          onClick={() => {
                            // Define the item you want to add to the cart
                            const itemToAdd: CartItem = {
                              id: 1,
                              name: 'Delicious Pizza',
                              price: 20,
                              img: f1,
                            };

                            // Call the addToCart function to add the item to the cart
                            addToCart(itemToAdd);
                          }}
                        >
                          <i className="lni lni-cart" style={{ color: 'aliceblue' }}></i>
                        </a>
                      </div>
                    </div>
                  </div>
                </div>
              </div>
              <div className="col-sm-6 col-lg-4 all burger">
                <div className="box">
                  <div>
                    <div className="img-box">
                      <img src={f2} alt="" />
                    </div>
                    <div className="detail-box">
                      <h5>Delicious Burger</h5>
                      <p>
                        Choose your favorite burger with a variety of toppings
                        to choose from!
                      </p>
                      <div className="options">
                        <h6>R15</h6>
                        <a
                          href="#"
                          onClick={() => {
                            // Define the item you want to add to the cart
                            const itemToAdd: CartItem = {
                              id: 2,
                              name: 'Delicious Burger',
                              price: 15,
                              img: f2,
                            };

                            // Call the addToCart function to add the item to the cart
                            addToCart(itemToAdd);
                          }}
                        >
                          <i className="lni lni-cart" style={{ color: 'aliceblue' }}></i>
                        </a>
                      </div>
                    </div>
                  </div>
                </div>
              </div>
              <div className="col-sm-6 col-lg-4 all pizza">
                <div className="box">
                  <div>
                    <div className="img-box">
                      <img src={f3} alt="" />
                    </div>
                    <div className="detail-box">
                      <h5>Delicious Pizza</h5>
                      <p>
                        It's pizza time! Choose your favorite pizza with a
                        variety of toppings to choose from!
                      </p>
                      <div className="options">
                        <h6>R17</h6>
                        <a
                          href="#"
                          onClick={() => {
                            // Define the item you want to add to the cart
                            const itemToAdd: CartItem = {
                              id: 3,
                              name: 'Delicious Pizza',
                              price: 17,
                              img: f3,
                            };

                            // Call the addToCart function to add the item to the cart
                            addToCart(itemToAdd);
                          }}
                        >
                          <i className="lni lni-cart" style={{ color: 'aliceblue' }}></i>
                        </a>
                      </div>
                    </div>
                  </div>
                </div>
              </div>
              <div className="col-sm-6 col-lg-4 all pasta">
                <div className="box">
                  <div>
                    <div className="img-box">
                      <img src={f4} alt="" />
                    </div>
                    <div className="detail-box">
                      <h5>Delicious Pasta</h5>
                      <p>
                        Mamma Mia! Choose your favorite pasta with a variety of
                        toppings to choose from!
                      </p>
                      <div className="options">
                        <h6>R18</h6>
                        <a
                          href="#"
                          onClick={() => {
                            // Define the item you want to add to the cart
                            const itemToAdd: CartItem = {
                              id: 44,
                              name: 'Delicious Pasta',
                              price: 18,
                              img: f4,
                            };

                            // Call the addToCart function to add the item to the cart
                            addToCart(itemToAdd);
                          }}
                        >
                          <i className="lni lni-cart" style={{ color: 'aliceblue' }}></i>
                        </a>
                      </div>
                    </div>
                  </div>
                </div>
              </div>
              <div className="col-sm-6 col-lg-4 all fries">
                <div className="box">
                  <div>
                    <div className="img-box">
                      <img src={f5} alt="" />
                    </div>
                    <div className="detail-box">
                      <h5>French Fries</h5>
                      <p>
                        All American? Enjoy our fries right here at Everest!
                      </p>
                      <div className="options">
                        <h6>R10</h6>
                        <a
                          href="#"
                          onClick={() => {
                            // Define the item you want to add to the cart
                            const itemToAdd: CartItem = {
                              id: 5,
                              name: 'French Fries',
                              price: 10,
                              img: f5,
                            };

                            // Call the addToCart function to add the item to the cart
                            addToCart(itemToAdd);
                          }}
                        >
                          <i className="lni lni-cart" style={{ color: 'aliceblue' }}></i>
                        </a>
                      </div>
                    </div>
                  </div>
                </div>
              </div>
              <div className="col-sm-6 col-lg-4 all pasta">
                <div className="box">
                  <div>
                    <div className="img-box">
                      <img src={f9} alt="" />
                    </div>
                    <div className="detail-box">
                      <h5>Delicious Pasta</h5>
                      <p>
                        Pasta lover? Just like us! Choose from Greek, Italian, or
                        American pasta!
                      </p>
                      <div className="options">
                        <h6>R10</h6>
                        <a
                          href="#"
                          onClick={() => {
                            // Define the item you want to add to the cart
                            const itemToAdd: CartItem = {
                              id: 16,
                              name: 'Delicious Pasta',
                              price: 10,
                              img: f9,
                            };

                            // Call the addToCart function to add the item to the cart
                            addToCart(itemToAdd);
                          }}
                        >
                          <i className="lni lni-cart" style={{ color: 'aliceblue' }}></i>
                        </a>
                      </div>
                    </div>
                  </div>
                </div>
              </div>
            </div>
          </div>
        </div>
      </section>
      <footer className="footer_section">
        <div className="container">
          <div className="row">
            <div className="col-md-4 footer-col">
              <div className="footer_contact">
                <h4>Contact Us</h4>
                <div className="contact_link_box">
                  <a href="">
                    <i className="fa fa-map-marker" aria-hidden="true"></i>
                    <span>Location</span>
                  </a>
                  <a href="">
                    <i className="fa fa-phone" aria-hidden="true"></i>
                    <span>Call +01 1234567890</span>
                  </a>
                  <a href="">
                    <i className="fa fa-envelope" aria-hidden="true"></i>
                    <span>demo@gmail.com</span>
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
                  <br />
                  <i>"Prepare for a food experience that will leave you craving for more!"</i>
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
              <h4>Opening Hours</h4>
              <p>Everyday</p>
              <p>10.00 AM - 10.00 PM</p>
            </div>
          </div>
          <div className="footer-info">
            <p>
              &copy; <span id="displayYear"></span> All Rights Reserved By Everest
            </p>
          </div>
        </div>
      </footer>
    </div>
  );
};

export default Menu;

