import { Link } from "react-router-dom";
import { useCartStore } from "../stateStore";
import { faSearch, faShoppingCart, faUser } from "@fortawesome/free-solid-svg-icons";
import { FontAwesomeIcon } from "@fortawesome/react-fontawesome";

type NavbarProps = {
  route: string;
}

const Navbar = (props: NavbarProps) => {
    
    const { cartItems } = useCartStore((state) => {return { cartItems: state.cartItems };});

    return (
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
                  <li className={"nav-item " + (props.route === "Menu" ? "active" : "")}>
                    <Link className="nav-link" to="/menu"><span>Menu</span></Link>
                  </li>
                  <li className={"nav-item " + (props.route === "About" ? "active" : "")}>
                    <Link className="nav-link" to="/about"><span>About</span></Link>
                  </li>
                  <li className={"nav-item " + (props.route === "Book" ? "active" : "")}>
                    <Link className="nav-link" to="/book"><span>Book</span></Link>
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
                  <Link className="order_online" to='/menu'><span>Order Online</span></Link>
                </div>
              </div>
            </nav>
          </div>
        </header>
    )
}

export default Navbar