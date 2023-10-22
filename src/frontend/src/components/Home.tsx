import React from 'react';

import '../css/bootstrap.css';
import '../css/style.css';
import '../css/responsive.css';
import '../css/font-awesome.min.css';
import '../css/style.scss';
// import '../css/style.css.map';
import '../fonts/fontawesome-webfont.ttf';
import '../fonts/fontawesome-webfont.woff';
import '../fonts/fontawesome-webfont.woff2';
// import './js/bootstrap.js';
// import './js/custom.js';
// import './js/jquery-3.4.1.min.js';
// Home.tsx

const Home: React.FC = () => {
  return (
    <div>
      <div className="hero_area">
        <div className="bg-box">
          <img src="../assets/images/hero-bg.jpg" alt="" />
        </div>
        <header className="header_section">
          <div className="container">
            <nav className="navbar navbar-expand-lg custom_nav-container">
              <a className="navbar-brand" href="game.html">
                <span>Everest</span>
              </a>
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
                        <h1>Fast Food Restaurant</h1>
                        <p>
                          Welcome to Everest, the ultimate destination for mouthwatering fast food in Pretoria, South Africa!
                        </p>
                        <div className="btn-box">
                          <a href="menu.html" className="btn1">
                            Order Now
                          </a>
                        </div>
                      </div>
                    </div>
                  </div>
                </div>
              </div>
              <div className="carousel-item">
                <div className="container">
                  <div className="row">
                    <div className="col-md-7 col-lg-6">
                      <div className="detail-box">
                        <h1>Fast Food Restaurant</h1>
                        <p>
                          Indulge in our delectable menu and experience the flavors that will take your taste buds to new heights.
                        </p>
                        <div className="btn-box">
                          <a href="" className="btn1">
                            Order Now
                          </a>
                        </div>
                      </div>
                    </div>
                  </div>
                </div>
              </div>
              <div className="carousel-item">
                <div className="container">
                  <div className="row">
                    <div className="col-md-7 col-lg-6">
                      <div className="detail-box">
                        <h1>Fast Food Restaurant</h1>
                        <p>
                          Join us at Everest and embark on a culinary journey like no other. Satisfaction guaranteed, one bite at a time!
                        </p>
                        <div className="btn-box">
                          <a href="" className="btn1">
                            Order Now
                          </a>
                        </div>
                      </div>
                    </div>
                  </div>
                </div>
              </div>
            </div>
            <div className="container">
              <ol className="carousel-indicators">
                <li data-target="#customCarousel1" data-slide-to="0" className="active"></li>
                <li data-target="#customCarousel1" data-slide-to="1"></li>
                <li data-target="#customCarousel1" data-slide-to="2"></li>
              </ol>
            </div>
          </div>
        </section>
      </div>
    </div>
  );
};

export default Home;
