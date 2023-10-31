import { create } from 'zustand';
import { devtools, persist } from 'zustand/middleware';
import { CartState, foodProcessingState, waiterState } from './types';

export const useCartStore = create<CartState>()(
    devtools(
        persist(
        (set) => ({
            cartItems: [],
            addToCart: (item) => set((state) => ({cartItems: [...state.cartItems, item,],})),
            deleteFromCart: (id) => set((state) => ({cartItems: state.cartItems.filter((item) => item.id !== id),})),
        }),
        {name: 'CartState',}
        )
    )
)

export const usefoodProcessingTimeStore = create<foodProcessingState>()(
    devtools(
        persist(
        (set) => ({
            foodProcessingTime: 0,
            setFoodProcessingTime: (setTo) => set((state) => ({ foodProcessingTime: setTo })),
        }),
        {name: 'foodProcessingTime',}
        )
    )
)

export const useWaiterStore = create<waiterState>()(
    devtools(
        persist(
        (set) => ({
            waiterName: "",
            setWaiterName: (setTo) => set((state) => ({ waiterName: setTo })),
        }),
        {name: 'waiterName',}
        )
    )
)