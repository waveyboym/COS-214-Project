import React from 'react';
import '../fonts/fontawesome-webfont.ttf';
import '../fonts/fontawesome-webfont.woff';
import '../fonts/fontawesome-webfont.woff2';

// Import Swiper React components
import { Swiper, SwiperSlide } from 'swiper/react';
import { Link } from 'react-router-dom'; // Import Link from react-router-dom

// Import Swiper styles
import 'swiper/css';
import 'swiper/css/pagination';

import { hero_bg } from '../assets';

// import required modules
import { Autoplay, Pagination } from 'swiper/modules';

const Home: React.FC = () => {
  return (
    <div>
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
            </nav>
          </div>
        </header>
        <section className="slider_section">
          <div id="customCarousel1" className="carousel slide" data-ride="carousel">
            <Swiper
              spaceBetween={30}
              centeredSlides={true}
              autoplay={{
                delay: 2500,
                disableOnInteraction: true,
              }}
              style={{
                '--swiper-pagination-color': '#ffbe33',//just leave this alone if vscode underlines it in red squigglies
              }}
              pagination={{
                clickable: true,
              }}
              navigation={true}
              modules={[Autoplay, Pagination]}
              >
                <SwiperSlide>
                  <div className="container">
                    <div className="row">
                      <div className="col-md-7 col-lg-6">
                        <div className="detail-box">
                          <h1>Fast Food Restaurant</h1>
                          <p>
                            Welcome to Everest, the ultimate destination for mouthwatering fast food in Pretoria, South Africa!
                          </p>
                          <div className="btn-box">
                          <Link to="/menu">Order Now</Link>
                          </div>
                        </div>
                      </div>
                    </div>
                  </div>
                </SwiperSlide>
                <SwiperSlide>
                  <div className="container">
                    <div className="row">
                      <div className="col-md-7 col-lg-6">
                        <div className="detail-box">
                          <h1>Fast Food Restaurant</h1>
                          <p>
                            Indulge in our delectable menu and experience the flavors that will take your taste buds to new heights.
                          </p>
                          <div className="btn-box">
                            <Link to="/menu">Order Now</Link>
                          </div>
                        </div>
                      </div>
                    </div>
                  </div>
                </SwiperSlide>
                <SwiperSlide>
                  <div className="container">
                    <div className="row">
                      <div className="col-md-7 col-lg-6">
                        <div className="detail-box">
                          <h1>Fast Food Restaurant</h1>
                          <p>
                            Join us at Everest and embark on a culinary journey like no other. Satisfaction guaranteed, one bite at a time!
                          </p>
                          <div className="btn-box">
                            <Link to="/menu">Order Now</Link>
                          </div>
                        </div>
                      </div>
                    </div>
                  </div>
                </SwiperSlide>
            </Swiper>
          </div>
        </section>
      </div>
    </div>
  );
};

export default Home;
