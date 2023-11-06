import { create } from 'zustand';
import { CartState, apikeyState, foodProcessingState, seatedState, waiterState } from './types';

export const useCartStore = create<CartState>()(
    (set) => ({
            cartItems: [],
            addToCart: (item) => set((state) => ({cartItems: [...state.cartItems, item,],})),
            deleteFromCart: (id) => set((state) => ({cartItems: state.cartItems.filter((item) => item.id !== id),})),
            cleanCart: () => set((state) => ({cartItems: state.cartItems.splice(0, state.cartItems.length),})),
        })
)

export const usefoodProcessingTimeStore = create<foodProcessingState>()(
    (set) => ({
            foodProcessingTime: 0,
            setFoodProcessingTime: (setTo) => set((state) => ({ foodProcessingTime: setTo })),
        })
)

export const useWaiterStore = create<waiterState>()(
    (set) => ({
            waitTime: "",
            setwaitTime: (setTo) => set((state) => ({ waitTime: setTo })),
        })
)

export const useApiKeyStore = create<apikeyState>()(
    (set) => ({
            apikey: "",
            setApiKey: (setTo) => set((state) => ({ apikey: setTo })),
        })
)

export const useSeatedStore = create<seatedState>()(
    (set) => ({
            seated: false,
            setSeated: (setTo) => set((state) => ({ seated: setTo })),
        })
)