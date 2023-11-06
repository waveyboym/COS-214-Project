/**
*@file main.cpp
*@class none
*@author Michael
*@brief entry point of application
*/

//every file that you want compiled must be included in this main file
//if the another file is dependent on that file, it should go above that file's include command
#include <thread>
#include "backend/color/color.cpp"
#include "backend/States/EmotionalState.cpp"
#include "backend/Collectable/Collectable.cpp"

#include "backend/States/Angry.cpp"
#include "backend/States/Happy.cpp"
#include "backend/States/Neutral.cpp"
#include "backend/States/SlightlyAngry.cpp"
#include "backend/States/SlightlyHappy.cpp"

#include "backend/Meal/Meal.cpp"
#include "backend/Meal/Bun.cpp"
#include "backend/Meal/ConcreteBuns.cpp"
#include "backend/Meal/Ingredient.cpp"
#include "backend/Meal/ConcreteIngredients.cpp"
#include "backend/Orders/Order.cpp"

#include "backend/Orders/AddBBQSauce.cpp"
#include "backend/Orders/AddBeefBurgerPatty.cpp"
#include "backend/Orders/AddCaramelizedOnion.cpp"
#include "backend/Orders/AddCheese.cpp"
#include "backend/Orders/AddChickenBurgerPatty.cpp"
#include "backend/Orders/AddColdDrink.cpp"
#include "backend/Orders/AddFries.cpp"
#include "backend/Orders/AddJuice.cpp"
#include "backend/Orders/AddLettuce.cpp"
#include "backend/Orders/AddMayo.cpp"
#include "backend/Orders/AddNoBun.cpp"
#include "backend/Orders/AddNormalBun.cpp"
#include "backend/Orders/AddOnion.cpp"
#include "backend/Orders/AddPickles.cpp"
#include "backend/Orders/AddPineapple.cpp"
#include "backend/Orders/AddTomato.cpp"
#include "backend/Orders/AddVeggieBurgerPatty.cpp"
#include "backend/Orders/AddWater.cpp"
#include "backend/Orders/AddWholeWheatBun.cpp"

#include "backend/Table/Table.cpp"
#include "backend/Table/SingleTable.cpp"
#include "backend/Table/JoinedTable.cpp"

#include "backend/Bill/Bill.cpp"
#include "backend/Bill/MainBill.cpp"
#include "backend/Bill/SubBill.cpp"

#include "backend/People/People.cpp"
#include "backend/People/Customer.cpp"
#include "backend/People/Waiter.cpp"

#include "backend/Iterators/RestaurantIterator.cpp"
#include "backend/Iterators/BillIterator.cpp"
#include "backend/Iterators/JoinedTableIterator.cpp"
#include "backend/Iterators/SingleTableIterator.cpp"
#include "backend/Iterators/CustomerIterator.cpp"
#include "backend/Iterators/WaiterIterator.cpp"

#include "backend/Kitchen/Kitchen.cpp"
#include "backend/Kitchen/AbstractChef.cpp"
#include "backend/Kitchen/BunChef.cpp"
#include "backend/Kitchen/Chef.cpp"
#include "backend/Kitchen/HeadChef.cpp"

#include "backend/MaitreD/MaitreD.cpp"
#include "backend/MaitreD/ConcreteMaitreD.cpp"

#include "backend/SimulationInterface/SimulationInterface.cpp"
#include "backend/Restaurant/Restaurant.cpp"
#include "App/Application.cpp"

/**
*@brief entry point of application
*/
int main(){
    Application app; //set up application
    app.initApp(); //initialise app
    std::thread runnable_app_func(&Application::progressForward, &app);
    app.runApp(); //run app
    runnable_app_func.join();
    return EXIT_SUCCESS;
}
