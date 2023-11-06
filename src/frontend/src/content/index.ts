import { f2, f5} from "../assets/";
import steak from "../assets/steak.jpg";
import chicken from "../assets/chicken.jpg";
import lettuce from "../assets/lettuce.jpg";
import tomatoe from "../assets/tomatoe.jpg";
import salad from "../assets/salad.jpg";

const MenuItems = [
    {
        key: 0,
        image: f2,
        title: "Delicious Burger",
        description: "Choose your favorite burger with a variety of toppings to choose from!",
        price: 15,
        category: 'burger'
    },
    {
        key: 1,
        image: f5,
        title: "French Fries",
        description: "All American? Enjoy our fries right here at Everest!",
        price: 10,
        category: 'fries'
    },
    {
        key: 2,
        image: steak,
        title: "Steaks and Lettuce",
        description: "Juicy steaks served with fresh lettuce, a perfect combo!",
        price: 25,
        category: 'steak'
    },
    {
        key: 3,
        image: chicken,
        title: "Chicken Strips",
        description: "Delicious chicken strips served with your choice of dipping sauce!",
        price: 12,
        category: 'chicken'
    },
    {
        key: 4,
        image: lettuce,
        title: "Extra Lettuce",
        description: "Add some extra fresh lettuce to your meal for a healthy touch!",
        price: 3,
        category: 'lettuce'
    },
    {
        key: 5,
        image: tomatoe,
        title: "Tomatoes",
        description: "Fresh, ripe tomatoes to add to your favorite dishes!",
        price: 4,
        category: 'tomatoe'
    },
    {
        key: 6,
        image: salad,
        title: "Salad",
        description: "Fresh salad with your choice of dressing!",
        price: 8,
        category: 'salad'
    }
];

export default MenuItems;
