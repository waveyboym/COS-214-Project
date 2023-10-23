import React, { useState } from 'react';

//import lineicons

//import pictures
import { hero_bg } from '../assets';
import { Footer, Navbar } from '../components';
import { MenuItems } from '../content';
import FoodCard from '../components/FoodCard';
import { AnimatePresence } from "framer-motion";

const Menu: React.FC = () => {

  const [filteredItems, setfilteredItems] = useState(MenuItems);
  const [filtered, setFiltered] = useState<string>("All");

  const setFilterTo = (filter: string) => {
    if(filter === "All"){
      setFiltered("All");
      setfilteredItems(MenuItems);
    }
    else {
      setFiltered(filter);
      setfilteredItems(
        MenuItems.filter(item => {
              const check: string = item.title.toLowerCase();
                if (check.includes(filter.toLowerCase()))return true
                else return false
              })
            )
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
            <h2>Our Menu</h2>
          </div>
          <ul className="filters_menu">
            <li className={filtered === "All" ? "active" : ""} onClick={() => setFilterTo("All")} data-filter="*">All</li>
            <li className={filtered === "burger" ? "active" : ""} onClick={() => setFilterTo("burger")} data-filter=".burger">Burger</li>
            <li className={filtered === "pizza" ? "active" : ""} onClick={() => setFilterTo("pizza")} data-filter=".pizza">Pizza</li>
            <li className={filtered === "pasta" ? "active" : ""} onClick={() => setFilterTo("pasta")} data-filter=".pasta">Pasta</li>
            <li className={filtered === "fries" ? "active" : ""} onClick={() => setFilterTo("fries")} data-filter=".fries">Fries</li>
          </ul>
          <div className="filters-content">
            <div className="row grid">
            <AnimatePresence>
                {
                  filteredItems.map((item) => 
                    <FoodCard key={item.key} id={item.key} image={item.image} title={item.title} description={item.description} price={item.price}/>
                  )
                }
              </AnimatePresence>
            </div>
          </div>
        </div>
      </section>
      <Footer />
    </div>
  );
};

export default Menu;
