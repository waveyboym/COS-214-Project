import React, { useState } from 'react';

//import lineicons

//import pictures
import { hero_bg } from '../assets';
import { Footer, Navbar, FoodCard, EmotionalStateTab, TrackingComponent } from '../components';
import MenuItems from '../content';
import { AnimatePresence } from "framer-motion";
import TrackingBooking from './TrackingBooking';

const BookingMenu: React.FC = () => {
 const [filteredItems, setFilteredItems] = useState(MenuItems);
    const [filtered, setFiltered] = useState<string>("All");
    const [emotionalState, setEmotionalState] = useState('neutral'); // Define and set emotionalState

    const setFilterTo = (filter: string) => {
        if (filter === "All") {
            setFiltered("All");
            setFilteredItems(MenuItems);
        } else {
            setFiltered(filter);
            setFilteredItems(
                MenuItems.filter(item => {
                    const check: string = item.title.toLowerCase();
                    if (check.includes(filter.toLowerCase())) return true;
                    else return false;
                })
            );
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
                        <h2>Booking Menu</h2>
                        <h5>Pick and choose your favorites</h5>
                    </div>
                    <ul className="filters_menu">
                        <li className={filtered === "All" ? "active" : ""} onClick={() => setFilterTo("All")} data-filter="*">
                            All
                        </li>
                        <li className={filtered === "burger" ? "active" : ""} onClick={() => setFilterTo("burger")} data-filter=".burger">
                            Burger
                        </li>
                        <li className={filtered === "pizza" ? "active" : ""} onClick={() => setFilterTo("pizza")} data-filter=".pizza">
                            Pizza
                        </li>
                        <li className={filtered === "pasta" ? "active" : ""} onClick={() => setFilterTo("pasta")} data-filter=".pasta">
                            Pasta
                        </li>
                        <li className={filtered === "fries" ? "active" : ""} onClick={() => setFilterTo("fries")} data-filter=".fries">
                            Fries
                        </li>
                        <li className={filtered === "steaks" ? "active" : ""} onClick={() => setFilterTo("steaks")} data-filter=".steaks">
                            Steaks and Lettuce
                        </li>
                        <li className={filtered === "chicken" ? "active" : ""} onClick={() => setFilterTo("chicken")} data-filter=".chicken">
                            Chicken Strips
                        </li>
                        <li className={filtered === "lettuce" ? "active" : ""} onClick={() => setFilterTo("lettuce")} data-filter=".lettuce">
                            Extra Lettuce
                        </li>
                        <li className={filtered === "tomatoes" ? "active" : ""} onClick={() => setFilterTo("tomatoes")} data-filter=".tomatoes">
                            Tomatoes
                        </li>
                        <li className={filtered === "sundae" ? "active" : ""} onClick={() => setFilterTo("sundae")} data-filter=".sundae">
                            Sundae
                        </li>
                        <li className={filtered === "salad" ? "active" : ""} onClick={() => setFilterTo("salad")} data-filter=".salad">
                            Salad
                        </li>

                    </ul>
                    <div className="filters-content">
                        <div className="row grid">
                            <AnimatePresence>
                                {
                                    filteredItems.map((item) =>
                                        <FoodCard key={item.key} id={item.key} image={item.image} title={item.title} description={item.description} price={item.price} />
                                    )
                                }
                            </AnimatePresence>
                        </div>
                    </div>
                </div>
            </section>
            <EmotionalStateTab setEmotionalState={setEmotionalState} />
            <TrackingBooking orderStatus="In Progress" date="2023-11-01" emotionalState={emotionalState} />
            <Footer />
        </div>
    );
};

export default BookingMenu;

