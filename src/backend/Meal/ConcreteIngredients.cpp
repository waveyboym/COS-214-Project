#include "../includes/ConcreteIngredients.hpp"

//Patties
BeefPatty::BeefPatty(std::shared_ptr<Meal> meal) : Ingredient("Beef Patty", 10, meal){}
ChickenPatty::ChickenPatty(std::shared_ptr<Meal> meal) : Ingredient("Chicken Patty", 10.99, meal){}
VeggiePatty::VeggiePatty(std::shared_ptr<Meal> meal) : Ingredient("Chicken Patty", 8.52, meal){}

//Toppings
Pickles::Pickles(std::shared_ptr<Meal> meal) : Ingredient("Pickles", 4, meal){}
Onion::Onion(std::shared_ptr<Meal> meal) : Ingredient("Fresh Red Onion", 3.12, meal){}
CaramelizedOnion::CaramelizedOnion(std::shared_ptr<Meal> meal) : Ingredient("Caramelized Onion", 6.54, meal){}
Tomato::Tomato(std::shared_ptr<Meal> meal) : Ingredient("Tomato", 2.57, meal){}
Cheese::Cheese(std::shared_ptr<Meal> meal) : Ingredient("Cheese", 4.38, meal){}
Lettuce::Lettuce(std::shared_ptr<Meal> meal) : Ingredient("Lettuce", 1.20, meal){}
Pineapple::Pineapple(std::shared_ptr<Meal> meal) : Ingredient("Pineapple", 12.99, meal){}

//Side Dishes
Fries::Fries(std::shared_ptr<Meal> meal) : Ingredient("Fries", 10.25, meal){}
Salad::Salad(std::shared_ptr<Meal> meal) : Ingredient("Salad", 11.15, meal){}

//Sauces
TomatoSauce::TomatoSauce(std::shared_ptr<Meal> meal) : Ingredient("Tomato Sauce", 2.01, meal){}
BBQSauce::BBQSauce(std::shared_ptr<Meal> meal) : Ingredient("Barbecue Sauce", 2.14, meal){}
Mayo::Mayo(std::shared_ptr<Meal> meal) : Ingredient("Mayonnaise", 2.18, meal){}

//Drinks
Water::Water(std::shared_ptr<Meal> meal) : Ingredient("Water", 0, meal){}
ColdDrink::ColdDrink(std::shared_ptr<Meal> meal) : Ingredient("Cold Drink",12.30, meal){}
Juice::Juice(std::shared_ptr<Meal> meal) : Ingredient("Juice", 14.36, meal){}