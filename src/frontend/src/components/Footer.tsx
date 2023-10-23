import { FontAwesomeIcon } from '@fortawesome/react-fontawesome';
import { faEnvelope, faMapMarker, faPhone } from '@fortawesome/free-solid-svg-icons';
import { faFacebook } from '@fortawesome/free-brands-svg-icons';
import { faTwitter } from '@fortawesome/free-brands-svg-icons/faTwitter';
import { faLinkedin } from '@fortawesome/free-brands-svg-icons/faLinkedin';
import { faInstagram } from '@fortawesome/free-brands-svg-icons/faInstagram';
import { faPinterest } from '@fortawesome/free-brands-svg-icons/faPinterest';

const Footer = () => {
    return (
        <footer className="footer_section">
        <div className="container">
          <div className="row">
            <div className="col-md-4 footer-col">
              <div className="footer_contact">
                <h4>Contact Us</h4>
                <div className="contact_link_box">
                  <a href="">
                    <FontAwesomeIcon icon={faMapMarker} />
                    <span>Location</span>
                  </a>
                  <a href="">
                    <FontAwesomeIcon icon={faPhone} />
                    <span>Call +01 1234567890</span>
                  </a>
                  <a href="">
                    <FontAwesomeIcon icon={faEnvelope} />
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
                    <FontAwesomeIcon icon={faFacebook} />
                  </a>
                  <a href="">
                    <FontAwesomeIcon icon={faTwitter} />
                  </a>
                  <a href="">
                    <FontAwesomeIcon icon={faLinkedin} />
                  </a>
                  <a href="">
                    <FontAwesomeIcon icon={faInstagram} />
                  </a>
                  <a href="">
                    <FontAwesomeIcon icon={faPinterest} />
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
    )
}

export default Footer