import { create } from 'zustand';
import { devtools, persist } from 'zustand/middleware';
import { CartState } from './types';

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