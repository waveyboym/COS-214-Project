import { Link } from 'react-router-dom';

const SplashPage = () => {
    return (
        <div className="hero_area">
                  <div className="bg-box">
                    <img src="https://img.freepik.com/fotos-premium/eine-pizza-mit-einem-fehlenden-stueck-und-dem-wort-pizza-darauf_572536-220.jpg?w=1060" alt="" />
                  </div>
                  <header className="header_section">
                    <div className="container">
                      <nav className="navbar navbar-expand-lg custom_nav-container">
                      <Link className="navbar-brand" to="/menu"><span>Everest</span></Link>
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
                                  <h1>
                                    Run your own restaurant or play as a customer.
                                  </h1>
                                  <div className="row">
                                    <div className="btn-box col-lg-6">
                                      <Link to="/home">Play as Customer</Link>
                                    </div>
                                    <div className="btn-box col-lg-6">
                                      <a href="" className="btn1">
                                        Play as Manager
                                      </a>
                                    </div>
                                  </div>
                                </div>
                              </div>
                            </div>
                          </div>
                        </div>
                      </div>
                    </div>
                  </section>
                </div>
    )
}

export default SplashPage