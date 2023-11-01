import { f1, f2, f3, f5, f9} from "../assets/";
import steak from "../assets/steak.jpg";
import chicken from "../assets/chicken.jpg";
import lettuce from "../assets/lettuce.jpg";
import tomatoe from "../assets/tomatoe.jpg";
import sundae from "../assets/sundae.jpg";
import salad from "../assets/salad.jpg";

const MenuItems = [
    {
        key: 0,
        image: f1,
        title: "Delicious Pizza",
        description: "Enjoy our delicious pizza with a variety of toppings to choose from!",
        price: 20
    },
    {
        key: 1,
        image: f2,
        title: "Delicious Burger",
        description: "Choose your favorite burger with a variety of toppings to choose from!",
        price: 15
    },
    {
        key: 2,
        image: f3,
        title: "Delicious Pizza",
        description: "It's pizza time! Choose your favorite pizza with a variety of toppings to choose from!",
        price: 17
    },
    {
        key: 3,
        image: f5,
        title: "French Fries",
        description: "All American? Enjoy our fries right here at Everest!",
        price: 10
    },
    {
        key: 4,
        image: f9,
        title: "Delicious Pasta",
        description: "Pasta lover? Just like us! Choose from Greek, Italian, or American pasta!",
        price: 10
    },
    {
        key: 5,
        image: steak,
        title: "Steaks and Lettuce",
        description: "Juicy steaks served with fresh lettuce, a perfect combo!",
        price: 25
    },
    {
        key: 6,
        image: chicken,
        title: "Chicken Strips",
        description: "Delicious chicken strips served with your choice of dipping sauce!",
        price: 12
    },
    {
        key: 7,
        image: lettuce,
        title: "Extra Lettuce",
        description: "Add some extra fresh lettuce to your meal for a healthy touch!",
        price: 3
    },
    {
        key: 8,
        image: tomatoe,
        title: "Tomatoes",
        description: "Fresh, ripe tomatoes to add to your favorite dishes!",
        price: 4
    },
    {
        key: 9,
        image: sundae,
        title: "Sundae",
        description: "Indulge in a delicious sundae with your choice of toppings!",
        price: 8
    },
    {
        key: 10,
        image: salad,
        title: "Salad",
        description: "Fresh salad with your choice of dressing!",
        price: 8
    }
];

export default MenuItems;
