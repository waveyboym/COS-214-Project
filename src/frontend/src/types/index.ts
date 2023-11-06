export interface CartItem {
    id: number;
    name: string;
    price: number;
    img: string;
    description: string;
    category: string;
    // Add other properties as needed
}

export interface CartState {
    cartItems: CartItem[];
    addToCart: (item: CartItem) => void;
    deleteFromCart: (id: number) => void;
}

export interface foodProcessingState {
    foodProcessingTime: number;
    setFoodProcessingTime: (setTo: number) => void;
}

export interface waiterState {
    waitTime: string;
    setwaitTime: (setTo: string) => void;
}

export interface apikeyState{
    apikey: string;
    setApiKey: (setTo: string) => void;
}

export interface seatedState{
    seated: boolean;
    setSeated: (setTo: boolean) => void;
}