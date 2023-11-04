/**
*@file ConcreteIngredients.hpp ConcreteIngredients.cpp 
*@author Jaide
*@brief File containing all Concrete Ingredient classes
*/
#ifndef CONCRETE_INGREDIENTS_HPP
#define CONCRETE_INGREDIENTS_HPP
#include "Ingredient.hpp"

/** @defgroup Patties 
 *  This is the first group of concrete ingredients
 *  @{
 */
/** @brief class BeefPatty in group Patties */
class BeefPatty: public Ingredient{
    public: 
        BeefPatty(std::shared_ptr<Meal> meal);
};

/** @brief class ChickenPatty in group Patties */
class ChickenPatty: public Ingredient{
    public: 
        ChickenPatty(std::shared_ptr<Meal> meal);
};

/** @brief class VeggiePatty in group Patties */
class VeggiePatty: public Ingredient{
    public:
        VeggiePatty(std::shared_ptr<Meal> meal);
};
  
/** @} */ // end of Patties


/** @defgroup Toppings
 *  This is the second group of concrete ingredients
 *  @{
 */
/** @brief class Pickles in group Toppings */
class Pickles: public Ingredient{
    public:
        Pickles(std::shared_ptr<Meal> meal);
};

/** @brief class Onion in group Toppings */
class Onion: public Ingredient{
    public:
        Onion(std::shared_ptr<Meal> meal);
};

/** @brief class CaramelizedOnion in group Toppings*/
class CaramelizedOnion: public Ingredient{
    public:
        CaramelizedOnion(std::shared_ptr<Meal> meal);
};

/** @brief class Tomato in group Toppings*/
class Tomato: public Ingredient{
    public:
        Tomato(std::shared_ptr<Meal> meal);
};

/** @brief class Cheese in group Toppings*/
class Cheese: public Ingredient{
    public:
        Cheese(std::shared_ptr<Meal> meal);
};

/** @brief class Lettuce in group Toppings*/
class Lettuce: public Ingredient{
    public:
        Lettuce(std::shared_ptr<Meal> meal);
};

/** @brief class Pineapple in group Toppings*/
class Pineapple: public Ingredient{
    public:
        Pineapple(std::shared_ptr<Meal> meal);
};
  
/** @} */ // end of Toppings
 

/** @defgroup Side Dishes
 *  This is the third group of concrete ingredients
 *  @{
 */

/** @brief class Fries in group Side Dishes*/
class Fries: public Ingredient{
    public:
        Fries(std::shared_ptr<Meal> meal);
};

/** @brief class Salad in group Side Dishes*/
class Salad: public Ingredient{
    public:
        Salad(std::shared_ptr<Meal> meal);
};

/** @} */ // end of Side Dishes


/** @defgroup Sauces
 *  This is the fourth group of concrete ingredients
 *  @{
 */

/** @brief class TomatoSauce in group Sauces*/
class TomatoSauce: public Ingredient{
    public:
        TomatoSauce(std::shared_ptr<Meal> meal);
};

/** @brief class BBQSauce in group Sauces*/
class BBQSauce: public Ingredient{
    public:
        BBQSauce(std::shared_ptr<Meal> meal);
};

/** @brief class Mayo in group Sauces*/
class Mayo: public Ingredient{
    public:
        Mayo(std::shared_ptr<Meal> meal);
};

/** @} */ // end of Sauces


/** @defgroup Drinks
 *  This is the fifth group of concrete ingredients
 *  @{
 */

/** @brief class Water in group Drinks*/
class Water: public Ingredient{
    public:
        Water(std::shared_ptr<Meal> meal);
};

/** @brief class ColdDrink in group Drinks*/
class ColdDrink: public Ingredient{
    public:
        ColdDrink(std::shared_ptr<Meal> meal);
};

/** @brief class Juice in group Drinks*/
class Juice: public Ingredient{
    public:
        Juice(std::shared_ptr<Meal> meal);
};

/** @} */ // end of Drinks


#endif