export interface CartItem {
    id: number;
    name: string;
    price: number;
    img: string;
    description: string;
    // Add other properties as needed
}

export interface CartState {
    cartItems: CartItem[];
    addToCart: (item: CartItem) => void;
    deleteFromCart: (id: number) => void;
}