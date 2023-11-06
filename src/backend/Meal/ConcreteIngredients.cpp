#include "../includes/ConcreteIngredients.hpp"

//Patties
BeefPatty::BeefPatty(std::shared_ptr<Meal> meal) : Ingredient("Beef Patty", 10, 6.4, meal){}
ChickenPatty::ChickenPatty(std::shared_ptr<Meal> meal) : Ingredient("Chicken Patty", 10.99, 6.5, meal){}
VeggiePatty::VeggiePatty(std::shared_ptr<Meal> meal) : Ingredient("Chicken Patty", 8.52, 6.6, meal){}

//Toppings
Pickles::Pickles(std::shared_ptr<Meal> meal) : Ingredient("Pickles", 4.0, 2.1, meal){}
Onion::Onion(std::shared_ptr<Meal> meal) : Ingredient("Fresh Red Onion", 3.12, 2.0, meal){}
CaramelizedOnion::CaramelizedOnion(std::shared_ptr<Meal> meal) : Ingredient("Caramelized Onion", 6.54, 5.6, meal){}
Tomato::Tomato(std::shared_ptr<Meal> meal) : Ingredient("Tomato", 2.57, 3.4, meal){}
Cheese::Cheese(std::shared_ptr<Meal> meal) : Ingredient("Cheese", 4.38, 1.2, meal){}
Lettuce::Lettuce(std::shared_ptr<Meal> meal) : Ingredient("Lettuce", 1.20, 1.0, meal){}
Pineapple::Pineapple(std::shared_ptr<Meal> meal) : Ingredient("Pineapple", 12.99, 4.7, meal){}

//Side Dishes
Fries::Fries(std::shared_ptr<Meal> meal) : Ingredient("Fries", 10.25, 3.8, meal){}
Salad::Salad(std::shared_ptr<Meal> meal) : Ingredient("Salad", 11.15, 10.5, meal){}

//Sauces
TomatoSauce::TomatoSauce(std::shared_ptr<Meal> meal) : Ingredient("Tomato Sauce", 2.01, 2.4, meal){}
BBQSauce::BBQSauce(std::shared_ptr<Meal> meal) : Ingredient("Barbecue Sauce", 2.14, 2.6, meal){}
Mayo::Mayo(std::shared_ptr<Meal> meal) : Ingredient("Mayonnaise", 2.18, 2.8, meal){}

//Drinks
Water::Water(std::shared_ptr<Meal> meal) : Ingredient("Water", 0.0, 3.0, meal){}
ColdDrink::ColdDrink(std::shared_ptr<Meal> meal) : Ingredient("Cold Drink",12.30, 5.7, meal){}
Juice::Juice(std::shared_ptr<Meal> meal) : Ingredient("Juice", 14.36, 4.7, meal){}