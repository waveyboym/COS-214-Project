import { FunctionComponent } from "react";
import { CartItem } from "../types";
import { useCartStore } from "../stateStore";
import { faCartShopping } from "@fortawesome/free-solid-svg-icons";
import { FontAwesomeIcon } from "@fortawesome/react-fontawesome";
import { motion } from "framer-motion";

type FoodCardProps = {
    id: number;
    image: string;
    title: string;
    description: string;
    price: number;
    category: string;
}

const FoodCard: FunctionComponent<FoodCardProps> = (props: FoodCardProps) => {

    const { addToCart } = useCartStore((state) => {return { addToCart: state.addToCart };});

    return (
        <motion.div 
        layout
        initial={{opacity: 0}}
        animate={{opacity: 1}}
        exit={{opacity: 0}}
        transition={{duration: 0.5}}
        className="col-sm-6 col-lg-4 all pizza">
            <div className="box">
                <div>
                <div className="img-box">
                    <img src={props.image} alt="" />
                </div>
                <div className="detail-box">
                    <h5>{props.title}</h5>
                    <p>{props.description}</p>
                    <div className="options">
                    <h6>R{props.price}</h6>
                    <a
                        href="#"
                        onClick={() => {
                        // Define the item you want to add to the cart
                        const itemToAdd: CartItem = {
                            id: props.id,
                            name: props.title,
                            price: props.price,
                            img: props.image,
                            description: props.description,
                            category: props.category
                        };

                        // Call the addToCart function to add the item to the cart
                        addToCart(itemToAdd);
                        }}
                    >
                        <FontAwesomeIcon icon={faCartShopping} />
                    </a>
                    </div>
                </div>
                </div>
            </div>
            </motion.div>
    )
}

export default FoodCard