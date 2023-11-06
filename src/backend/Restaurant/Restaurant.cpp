#include "../includes/Restaurant.hpp"
/*@note for any function that starts with FRONTEND, you are not allowed to edit it if you are not working on frontend*/

Restaurant::Restaurant(){
    num_seated_customers = 0;
    this->maitre_d = std::make_shared<ConcreteMaitreD>();
    //pre-determined number of waiters in the restaurant
    this->waiters["Dwain Barber"] = std::make_shared<Waiter>("Dwain Barber");
    this->waiters["Meredith Lin"] = std::make_shared<Waiter>("Meredith Lin");
    this->waiters["Gracie Mcpherson"] = std::make_shared<Waiter>("Gracie Mcpherson");
    this->waiters["Carson Welch"] = std::make_shared<Waiter>("Carson Welch");
    this->waiters["Kristi Cantrell"] = std::make_shared<Waiter>("Kristi Cantrell");
    this->waiters["Jana Robertson"] = std::make_shared<Waiter>("Jana Robertson");
    this->waiters["Georgette Rocha"] = std::make_shared<Waiter>("Georgette Rocha");
    this->waiters["Laurence Herman"] = std::make_shared<Waiter>("Laurence Herman");

    kitchen = std::make_shared<Kitchen>(this->waiters);

    //pre-determined number of tables in the restaurant
    this->single_tables.push_back(std::make_shared<SingleTable>(1));
    this->single_tables.push_back(std::make_shared<SingleTable>(2));
    this->single_tables.push_back(std::make_shared<SingleTable>(3));
    this->single_tables.push_back(std::make_shared<SingleTable>(4));
    this->single_tables.push_back(std::make_shared<SingleTable>(5));
    this->single_tables.push_back(std::make_shared<SingleTable>(6));
    this->single_tables.push_back(std::make_shared<SingleTable>(7));
    this->single_tables.push_back(std::make_shared<SingleTable>(8));
    this->single_tables.push_back(std::make_shared<SingleTable>(9));
    this->single_tables.push_back(std::make_shared<SingleTable>(10));
    this->single_tables.push_back(std::make_shared<SingleTable>(11));
    this->single_tables.push_back(std::make_shared<SingleTable>(12));
    this->single_tables.push_back(std::make_shared<SingleTable>(13));
    this->single_tables.push_back(std::make_shared<SingleTable>(14));
    this->single_tables.push_back(std::make_shared<SingleTable>(15));
    this->single_tables.push_back(std::make_shared<SingleTable>(16));
    this->single_tables.push_back(std::make_shared<SingleTable>(17));
    this->single_tables.push_back(std::make_shared<SingleTable>(18));
    this->single_tables.push_back(std::make_shared<SingleTable>(19));
    this->single_tables.push_back(std::make_shared<SingleTable>(20));
    this->single_tables.push_back(std::make_shared<SingleTable>(21));
    this->single_tables.push_back(std::make_shared<SingleTable>(22));
    this->single_tables.push_back(std::make_shared<SingleTable>(23));
    this->single_tables.push_back(std::make_shared<SingleTable>(24));
    this->single_tables.push_back(std::make_shared<SingleTable>(25));
    this->single_tables.push_back(std::make_shared<SingleTable>(26));
    this->single_tables.push_back(std::make_shared<SingleTable>(27));
    this->single_tables.push_back(std::make_shared<SingleTable>(28));
    this->single_tables.push_back(std::make_shared<SingleTable>(29));
    this->single_tables.push_back(std::make_shared<SingleTable>(30));

    this->joined_tables.push_back(std::make_shared<JoinedTable>(31));
    this->joined_tables.push_back(std::make_shared<JoinedTable>(32));
    this->joined_tables.push_back(std::make_shared<JoinedTable>(33));
    this->joined_tables.push_back(std::make_shared<JoinedTable>(34));
    this->joined_tables.push_back(std::make_shared<JoinedTable>(35));
    this->joined_tables.push_back(std::make_shared<JoinedTable>(36));
    this->joined_tables.push_back(std::make_shared<JoinedTable>(37));
    this->joined_tables.push_back(std::make_shared<JoinedTable>(38));
    this->joined_tables.push_back(std::make_shared<JoinedTable>(39));
    this->joined_tables.push_back(std::make_shared<JoinedTable>(40));
    this->joined_tables.push_back(std::make_shared<JoinedTable>(41));
    this->joined_tables.push_back(std::make_shared<JoinedTable>(42));
    this->joined_tables.push_back(std::make_shared<JoinedTable>(44));
    this->joined_tables.push_back(std::make_shared<JoinedTable>(45));
}

Restaurant::~Restaurant(){

}

std::shared_ptr<Restaurant> Restaurant::instance(){
    static std::shared_ptr<Restaurant> restaurant_object{new Restaurant};
    return restaurant_object;
}

std::string Restaurant::generateUUID(){
    std::random_device rd;
    auto seed_data = std::array<int, std::mt19937::state_size> {};
    std::generate(std::begin(seed_data), std::end(seed_data), std::ref(rd));
    std::seed_seq seq(std::begin(seed_data), std::end(seed_data));
    std::mt19937 generator(seq);
    uuids::uuid_random_generator gen{generator};

    uuids::uuid const idUUID = gen();

    std::string id = uuids::to_string(idUUID);

    return id;
}

void Restaurant::progressByOneStep(){
    int random_number = rand();

    if(random_number % 10 >= 0 && random_number % 10 <= 5){
        //0 to 10 customers should enter the restaurant
        this->customersEnterRestaurant(random_number);
    }
    if(random_number % 10 >= 0 && random_number % 10 <= 10){
        //seat customers who are not seated at an available table
        this->seatAnyCustomer(random_number);
    }
    if(random_number % 10 >= 0 && random_number % 10 <=10){
        //assign a free waiter to any table that has customers
        this->assignOneFreeWaiter();
    }
    if(random_number % 10 >= 0 && random_number % 10 <=1){
        //assign all free waiters to any table that has customers
        this->assignAllFreeWaiters();
    }
    if(random_number % 10 >= 0 && random_number % 10 < 7)
    {
        //0 to 6 customers will decide what to order
        setAnyCustomerOrder(random_number);
    }
    if(random_number % 10 >= 0 && random_number % 10 < 6)
    {
        //waiter will take orders
        waiterTakesOrder();
    }
    if(random_number % 10 >= 0 && random_number % 10 < 8)
    {
        //waiter will send orders to the kitchen to prepare
        ordersTakenToKitchen();
    }
    if(random_number % 10 >= 0 && random_number % 10 < 6)
    {
        //kitchen will tell waiters to take completed meals to customers
        deliverMeals();
    }
    if(random_number % 10 >= 0 && random_number % 10 <= 10){
        //assign a free waiter to any table that has customers
        this->unseatFinishedCustomers();
    }
}

void Restaurant::customersEnterRestaurant(int random_number){
    //0 to 10 customers should enter the restaurant
    int expected_customers = random_number % 10;
    std::cout << color::format_colour::make_colour(color::YELLOW) << expected_customers << " customers have just entered the restaurant" << color::format_colour::make_colour(color::DEFAULT) << std::endl;
    for(int i = 0; i < expected_customers; ++i){
        std::string id = "";
        while(true){
            id = this->generateUUID();
            if(!this->customers.contains(id)){
                this->customers[id] = std::make_shared<Customer>(id);
                std::cout << color::format_colour::make_colour(color::BLUE) << i << " has a uuid of: " << id << color::format_colour::make_colour(color::DEFAULT) << std::endl;
                break;
            }
        }
    }
}

void Restaurant::seatAnyCustomer(int random_number){
    int expected_to_seat_customers = random_number % 10;
    std::cout << color::format_colour::make_colour(color::YELLOW) << expected_to_seat_customers << " customers are being seated by the maitre-d if there is space for them all" << color::format_colour::make_colour(color::DEFAULT) << std::endl;
    
    std::shared_ptr<CustomerIterator> c_i = std::make_shared<CustomerIterator>(this->customers);
    int i = 0;

    while(!c_i->isDone() && i < expected_to_seat_customers){
        std::shared_ptr<Customer> customer = std::dynamic_pointer_cast<Customer>(c_i->currentItem());
        if(customer != nullptr && !customer->getIsSeated()){
            this->maitre_d->seatCustomer(this->single_tables, this->joined_tables, customer);
            std::cout << color::format_colour::make_colour(color::BLUE) <<"customer with uuid of: " << customer->getUUID() << " has been seated in the restaurant" << color::format_colour::make_colour(color::DEFAULT) << std::endl;
        }
        c_i->next();
        ++i;
        ++num_seated_customers;
    }
}

void Restaurant::unseatFinishedCustomers(){
    //find and unseats all finished customers
    //make an iterator
    std::shared_ptr<CustomerIterator> c_i = std::make_shared<CustomerIterator>(this->customers);
    //find the customers who are finished and unseat them
    while (!c_i->isDone())
    {
        std::shared_ptr<Customer> curCustomer = std::dynamic_pointer_cast<Customer>(c_i->currentItem());
        if (curCustomer != nullptr && curCustomer->getHasCompletedMeal() && !curCustomer->isAFrontendCustomer())
        {
            this->maitre_d->unseatCustomer(this->single_tables, this->joined_tables, curCustomer, this->waiters);
            std::cout << color::format_colour::make_colour(color::MAGENTA) <<"customer with uuid of: " << curCustomer->getUUID() << " has been unseated from the restaurant" << color::format_colour::make_colour(color::DEFAULT) << std::endl;
            this->customers.erase(curCustomer->getUUID());
        }
        c_i->next();
        --num_seated_customers;
    }
}

void Restaurant::assignOneFreeWaiter(){
    //assign first free waiter to any table that has customers seated
    //make iterator to check through waiters
    std::shared_ptr<WaiterIterator> w_i = std::make_shared<WaiterIterator>(this->waiters);
    //select the first free waiter to assign the table
    while(!w_i->isDone())
    { 
        std::shared_ptr<Waiter> curWaiter = std::dynamic_pointer_cast<Waiter>(w_i->currentItem());
        if (curWaiter != nullptr && !curWaiter->isAssignedATable())
        {
            this->maitre_d->assignWaiterToTable(this->single_tables, this->joined_tables, curWaiter);
            std::cout << color::format_colour::make_colour(color::GREEN) <<"waiter with uuid of: " << curWaiter->getUUID() << " has been assigned to the table with id of " << curWaiter->getAssignedTableID() << color::format_colour::make_colour(color::DEFAULT) << std::endl;
            break;
        }
        w_i->next();
    }
}

void Restaurant::assignAllFreeWaiters(){
    //assign first free waiter to any table that has customers seated
    //make iterator to check through waiters
    std::shared_ptr<WaiterIterator> w_i = std::make_shared<WaiterIterator>(this->waiters);
    //select the first free waiter to assign the table
    while(!w_i->isDone())
    { 
        std::shared_ptr<Waiter> curWaiter = std::dynamic_pointer_cast<Waiter>(w_i->currentItem());
        if (curWaiter != nullptr && !curWaiter->isAssignedATable())
        {
            this->maitre_d->assignWaiterToTable(this->single_tables, this->joined_tables, curWaiter);
            std::cout << color::format_colour::make_colour(color::GREEN) <<"waiter with uuid of: " << curWaiter->getUUID() << " has been assigned to the table with id of " << curWaiter->getAssignedTableID() << color::format_colour::make_colour(color::DEFAULT) << std::endl;
        }
        w_i->next();
    }
}

void Restaurant::setAnyCustomerOrder(int random_number){
    if(num_seated_customers == 0 || random_number == 0){
        return;
    }

    int num_orders_to_set = random_number % num_seated_customers;
    int num_orders_set = 0;

    std::cout << color::format_colour::make_colour(color::YELLOW) << "customers are deciding what to order" << color::format_colour::make_colour(color::DEFAULT) << std::endl;

    std::shared_ptr<CustomerIterator> c_i = std::make_shared<CustomerIterator>(this->customers);
    int i = 0;

    while(!c_i->isDone() && i < num_orders_to_set){
        std::shared_ptr<Customer> customer = std::dynamic_pointer_cast<Customer>(c_i->currentItem());
        if(customer->getIsSeated() && !customer->getHasDecided()){
            customer->setOrder();
            std::cout << color::format_colour::make_colour(color::BLUE) <<"customer with uuid of: " << customer->getUUID() << " has decided what to order" << color::format_colour::make_colour(color::DEFAULT) << std::endl;
            num_orders_set++;
        }
        c_i->next();
        ++i;
    }
}

void Restaurant::waiterTakesOrder(){
    std::cout << color::format_colour::make_colour(color::YELLOW) << "waiters are taking orders" << color::format_colour::make_colour(color::DEFAULT) << std::endl;
    
    for (auto i = waiters.begin(); i != waiters.end(); i++){
        std::shared_ptr<Waiter> waiter = i->second;
        int num_orders_taken = 0;
        if(waiter->isAssignedATable()){

            std::cout << color::format_colour::make_colour(color::GREEN) << i->first << " is taking the orders at the table with id " << waiter->getAssignedTableID() << color::format_colour::make_colour(color::DEFAULT) << std::endl;

            std::list<std::shared_ptr<Customer>> customer_list = waiter->getTable()->getAllSeatedCustomers();

            std::list<std::shared_ptr<Customer>>::iterator it;
            for (it = customer_list.begin(); it != customer_list.end(); ++it){
                std::shared_ptr<Customer> customer = *it;

                if(!customer->getHasOrdered() && customer->getHasDecided()){
                    waiter->takeOrder(*it);
                    customer->Ordered();

                    std::cout << color::format_colour::make_colour(color::BLUE) <<"customer with uuid of: " << customer->getUUID() << " has placed their order" << color::format_colour::make_colour(color::DEFAULT) << std::endl;

                    num_orders_taken++;
                }
            }
        }

        if(num_orders_taken == 0){
            std::cout << color::format_colour::make_colour(color::GREEN) << " there were no orders to take at " << i->first  << "'s table" << color::format_colour::make_colour(color::DEFAULT) << std::endl;
        }
    } 
}

void Restaurant::ordersTakenToKitchen(){
    std::cout << color::format_colour::make_colour(color::YELLOW) << "waiters are taking orders to the kitchen" << color::format_colour::make_colour(color::DEFAULT) << std::endl;

    for (auto i = waiters.begin(); i != waiters.end(); i++){
        std::shared_ptr<Waiter> waiter = i->second;

        if(waiter->getHasOrders()){
            std::pair<std::vector<std::shared_ptr<Order>>, std::shared_ptr<Customer>> orders = waiter->sendOrder();
            kitchen->createMeal(orders.first, orders.second);
            
            std::cout << color::format_colour::make_colour(color::CYAN) << "Kitchen is preparing order of customer with uuid: " << orders.second->getUUID() << color::format_colour::make_colour(color::DEFAULT) << std::endl;
        }      
    }
}

void Restaurant::deliverMeals(){
    if(kitchen->getHasCompletedMeals()){
        std::cout << color::format_colour::make_colour(color::CYAN) << "Orders are ready to be collected from the kitchen"  << color::format_colour::make_colour(color::DEFAULT) << std::endl;
        kitchen->notifyWaiters();
    }    
}

/*****************************************************************************************************************************


    DEBUG/TESTING METHODS


*******************************************************************************************************************************/

void Restaurant::DEBUG_setAllCustomers_hasCompletedMeal(bool inp){
    std::shared_ptr<CustomerIterator> c_i = std::make_shared<CustomerIterator>(this->customers);
    std::cout << color::format_colour::make_colour(color::GREEN) <<"Setting all customers' hasCompletedMeal variables to " << inp << color::format_colour::make_colour(color::DEFAULT) << std::endl;
    while (!c_i->isDone())
    {
        std::shared_ptr<Customer> curCustomer = std::dynamic_pointer_cast<Customer>(c_i->currentItem());
        curCustomer->setHasCompletedMeal(inp);
        c_i->next();
    }
}

























/*****************************************************************************************************************************


        FRONT END CODE, ONLY EDIT BELOW THIS SECTION IF YOU ARE WORKING ON FRONTEND



*******************************************************************************************************************************/

/*@note for any function that starts with FRONTEND, you are not allowed to edit it if you are not working on frontend*/
//customer
std::string Restaurant::FRONTEND_processUpdateCheck(json req_obj) {
    if (req_obj.find("token") != req_obj.end()) {
        std::string id = req_obj["token"];
        if (this->customers.contains(id)) {
            //Update the customer's check, dont know how to do this, we are still waiting on backend stuff for this.
            //bro I can't even access the expected meal cooking time :sob
            std::string status_of_food = (this->customers[id]->getHasCompletedMeal() == true ? "completed" : "not completed");
            return "{\"status\":\"success\",\"command\":\"update_check\",\"orderStatus\":\""+ status_of_food +"\",\"message\":\"Update check successful\"}";
        } else {
            return "{\"status\":\"error\",\"message\":\"Customer not found\"}";
        }
    } else {
        return "{\"status\":\"error\",\"message\":\"Token is missing\"}";
    }
}

std::string Restaurant::FRONTEND_processCustomerOrder(json req_obj) {
    std::vector<std::string> orders_items;
    for (auto& elem : req_obj["order"]){
        if(elem.contains("category")){
            orders_items.push_back(elem["category"]);
        }
        else{
            return "{\"status\":\"error\",\"message\":\"could not process order\"}";
        }
    }
    std::string id = req_obj["token"];
    if(!this->customers.contains(id)){
        return "{\"status\":\"error\",\"message\":\"this customer id does not exist\"}";
    }
    this->customers[id]->setFrontendOrder(orders_items);
    return "{\"status\":\"success\",\"player\":\"customer\",\"command\":\"create_order\",\"message\":\"""\"}";
}

std::string Restaurant::processFrontendRequest(std::string req){
    return "";
}

std::string Restaurant::FRONTEND_processCustomersEmotion(json req_obj) {
    std::string emotionalState = req_obj["emotional_state"];
    std::string id = req_obj["token"];

    std::shared_ptr<CustomerIterator> c_i = std::make_shared<CustomerIterator>(this->customers);
    while (!c_i->isDone())
    {
        std::shared_ptr<Customer> curCustomer = std::dynamic_pointer_cast<Customer>(c_i->currentItem());
        if(curCustomer != nullptr && curCustomer->getUUID() == id){
            if(emotionalState == "happy"){
                curCustomer->setEmotionalState(EMOTIONAL_STATE::HAPPY);
            }
            else if(emotionalState == "angry"){
                curCustomer->setEmotionalState(EMOTIONAL_STATE::ANGRY);
            }
            else if(emotionalState == "slightly_happy"){
                curCustomer->setEmotionalState(EMOTIONAL_STATE::SLIGHTLY_HAPPY);
            }
            else if(emotionalState == "slightly_angry"){
                curCustomer->setEmotionalState(EMOTIONAL_STATE::SLIGHTLY_ANGRY);
            }
            else if(emotionalState == "neutral"){
                curCustomer->setEmotionalState(EMOTIONAL_STATE::NEUTRAL);
            }
            else{
                return "{\"status\":\"error\",\"message\":\"no such emotional state exists\"}";
            }

            return "{\"status\":\"success\",\"player\":\"customer\",\"command\":\"change_emotional_state\",\"emotional_state\":\"" + emotionalState + "\"}";
        }
        c_i->next();
    }
    return "{\"status\":\"error\",\"message\":\"no customer with this uuid exists\"}";
}

std::string Restaurant::FRONTEND_processCheckOutCustomer(json req_obj) {
    if (req_obj.find("token") != req_obj.end()) {
        std::string id = req_obj["token"];
        if (this->customers.contains(id)) {
            this->maitre_d->unseatCustomer(this->single_tables, this->joined_tables, this->customers[id], this->waiters);
            this->customers.erase(id);
            std::cout << color::format_colour::make_colour(color::RED) << "customer with uuid of: " << id << " has checked out" << color::format_colour::make_colour(color::DEFAULT) << std::endl;
            return "{\"status\":\"success\",\"player\":\"customer\",\"command\":\"checkout\",\"message\":\"successfully checked out\"}";
        } else {
            return "{\"status\":\"error\",\"message\":\"Customer not found\"}";
        }
    } else {
        return "{\"status\":\"error\",\"message\":\"Token is missing\"}";
    }
}

std::string Restaurant::FRONTEND_processCustomerRestaurantEntry(json req_obj){
    std::string id = req_obj["token"];
    this->customers[id] = std::make_shared<Customer>(id);
    this->customers[id]->setIsAFrontendCustomer(true);
    std::cout << color::format_colour::make_colour(color::GREEN) <<"customer with uuid of: " << id << " has entered the restaurant" << color::format_colour::make_colour(color::DEFAULT) << std::endl;
    return "{\"status\":\"success\",\"player\":\"customer\",\"command\":\"add_token\",\"message\":\"successfully added customer token\"}";
}

std::string Restaurant::FRONTEND_processCustomerRestaurantExit(json req_obj){
    std::string id = req_obj["token"];
    if(this->customers.contains(id)){
        this->customers.erase(id);
        std::cout << color::format_colour::make_colour(color::RED) <<"customer with uuid of: " << id << " has left the restaurant" << color::format_colour::make_colour(color::DEFAULT) << std::endl;
        return "{\"status\":\"success\",\"player\":\"customer\",\"command\":\"exit_restaurant\",\"message\":\"exited\"}";
    }
    else {
        return "{\"status\":\"error\",\"message\":\"player does not exist\"}";
    }
}

std::string Restaurant::FRONTEND_processCustomerRequestSeat(json req_obj){
    std::string id = req_obj["token"];
    if(this->customers.contains(id)){
        if(this->maitre_d->seatCustomer(this->single_tables, this->joined_tables, this->customers[id])){
            std::cout << color::format_colour::make_colour(color::BLUE) <<"customer with uuid of: " << id << " has been seated in the restaurant" << color::format_colour::make_colour(color::DEFAULT) << std::endl;
            return "{\"status\":\"success\",\"player\":\"customer\",\"command\":\"seat_request\",\"message\":\"seated\"}";
        }
        else{
            return "{\"status\":\"error\",\"message\":\"the restaurant is full, try again later\"}";
        }
    }
    else {
        return "{\"status\":\"error\",\"message\":\"player does not exist\"}";
    }
}

std::string Restaurant::FRONTEND_processCustomerRequestUnSeat(json req_obj){
    std::string id = req_obj["token"];
    if(this->customers.contains(id)){
        if(this->maitre_d->unseatCustomer(this->single_tables, this->joined_tables, this->customers[id], this->waiters)){
            std::cout << color::format_colour::make_colour(color::BLUE) <<"customer with uuid of: " << id << " has been unseated in the restaurant" << color::format_colour::make_colour(color::DEFAULT) << std::endl;
            return "{\"status\":\"success\",\"player\":\"customer\",\"command\":\"seat_request\",\"message\":\"unseated\"}";
        }
        else{
            return "{\"status\":\"error\",\"message\":\"you could not be unseated\"}";
        }
    }
    else {
        return "{\"status\":\"error\",\"message\":\"player does not exist\"}";
    }
}

//manager
std::string Restaurant::FRONTEND_processManagerGetAll(json req_obj){
    std::string table_type_ = req_obj["table_type"];
    if(table_type_ == "waiters"){
        return "{"
                    "\"status\":\"success\","
                    "\"player\":\"manager\","
                    "\"command\":\"get_all\","
                    "\"message\":{"
                        "\"customer_count\":"+ std::to_string(this->customers.size()) +","
                        "\"waiter_count\":"+ std::to_string(this->waiters.size()) +","
                        "\"rating\":5"
                    "},"
                    "\"table_data\":" + this->FRONTEND_getTableObjects("waiters") +
                "}";
    }
    else if(table_type_ == "customers"){
        return "{"
                    "\"status\":\"success\","
                    "\"player\":\"manager\","
                    "\"command\":\"get_all\","
                    "\"message\":{"
                        "\"customer_count\":"+ std::to_string(this->customers.size()) +","
                        "\"waiter_count\":"+ std::to_string(this->waiters.size()) +","
                        "\"rating\":5"
                    "},"
                    "\"table_data\":" + this->FRONTEND_getTableObjects("customers") +
                "}";
    }
    else{
        return "{"
                    "\"status\":\"success\","
                    "\"player\":\"manager\","
                    "\"command\":\"get_all\","
                    "\"message\":{"
                        "\"customer_count\":"+ std::to_string(this->customers.size()) +","
                        "\"waiter_count\":"+ std::to_string(this->waiters.size()) +","
                        "\"rating\":5"
                    "},"
                    "\"table_data\":" + this->FRONTEND_getTableObjects("tables") +
                "}";
    }
}

std::string Restaurant::FRONTEND_processManagerGetTable(json req_obj){
    std::string table_type_ = req_obj["table_type"];
    if(table_type_ == "waiters"){
        return "{"
                "\"status\":\"success\","
                "\"player\":\"manager\","
                "\"command\":\"update_table\","
                "\"table_data\":" + this->FRONTEND_getTableObjects("waiters") +
            "}";
    }
    else if(table_type_ == "customers"){
        return "{"
                "\"status\":\"success\","
                "\"player\":\"manager\","
                "\"command\":\"update_table\","
                "\"table_data\":" + this->FRONTEND_getTableObjects("customers") +
            "}";
    }
    else{
        return "{"
                "\"status\":\"success\","
                "\"player\":\"manager\","
                "\"command\":\"update_table\","
                "\"table_data\":" + this->FRONTEND_getTableObjects("tables") +
            "}";
    }
}

std::string Restaurant::FRONTEND_getTableObjects(std::string type){
    if(type == "waiters"){
        std::shared_ptr<WaiterIterator> w_i = std::make_shared<WaiterIterator>(this->waiters);
        std::string to_return = "[";

        if(!w_i->isDone()){
            std::shared_ptr<Waiter> curr_waiter = std::dynamic_pointer_cast<Waiter>(w_i->currentItem());
            if(curr_waiter != nullptr)
            {
                to_return += "{\"name\":\""+ curr_waiter->getUUID() +"\",\"status\":\""+ (curr_waiter->isAssignedATable() == true ? "Assigned" : "Not Assigned") +"\",\"date\":\"07 November 2023\",\"progress\":0}";
            }
            w_i->next();
        }

        while(!w_i->isDone())
        { 
            std::shared_ptr<Waiter> curr_waiter = std::dynamic_pointer_cast<Waiter>(w_i->currentItem());
            if (curr_waiter != nullptr)
            {
                to_return += ",{\"name\":\""+ curr_waiter->getUUID() +"\",\"status\":\""+ (curr_waiter->isAssignedATable() == true ? "Assigned" : "Not Assigned") +"\",\"date\":\"07 November 2023\",\"progress\":0}";
            }
            w_i->next();
        }

        to_return += "]";
        return to_return;
    }
    else if(type == "customers"){
        std::shared_ptr<CustomerIterator> c_i = std::make_shared<CustomerIterator>(this->customers);
        std::string to_return = "[";

        if(!c_i->isDone()){
            std::shared_ptr<Customer> curr_customer = std::dynamic_pointer_cast<Customer>(c_i->currentItem());
            if(curr_customer != nullptr)
            {
                to_return += "{\"name\":\""+ curr_customer->getUUID() +"\",\"status\":\""+ (curr_customer->getIsSeated() == true ? "Assigned" : "Not Assigned") +"\",\"date\":\"" + curr_customer->getCurrentEmotionalStateString() + "\",\"progress\":0}";
            }
            c_i->next();
        }

        while(!c_i->isDone())
        { 
            std::shared_ptr<Customer> curr_customer = std::dynamic_pointer_cast<Customer>(c_i->currentItem());
            if (curr_customer != nullptr)
            {
                to_return += ",{\"name\":\""+ curr_customer->getUUID() +"\",\"status\":\""+ (curr_customer->getHasCompletedMeal() == true ? "Assigned" : "Not Assigned") +"\",\"date\":\"" + curr_customer->getCurrentEmotionalStateString() + "\",\"progress\":0}";
            }
            c_i->next();
        }

        to_return += "]";
        return to_return;
    }
    else{
        std::shared_ptr<SingleTableIterator> s_t_i = std::make_shared<SingleTableIterator>(this->single_tables);
        std::shared_ptr<JoinedTableIterator> j_t_i = std::make_shared<JoinedTableIterator>(this->joined_tables);
        std::string to_return = "[";

        if(!s_t_i->isDone()){
            std::shared_ptr<Table> table = std::dynamic_pointer_cast<Table>(s_t_i->currentItem());
            if(table != nullptr)
            {
                to_return += "{\"name\":\""+ std::to_string(table->getTableID()) +"\",\"status\":\""+ (table->isTableAvailable() == false ? "Assigned" : "Not Assigned") +"\",\"date\":\"07 November 2023\",\"progress\":0}";
            }
            s_t_i->next();
        }

        while(!s_t_i->isDone()){
            std::shared_ptr<Table> table = std::dynamic_pointer_cast<Table>(s_t_i->currentItem());
            if(table != nullptr){
                to_return += ",{\"name\":\""+ std::to_string(table->getTableID()) +"\",\"status\":\""+ (table->isTableAvailable() == false ? "Assigned" : "Not Assigned") +"\",\"date\":\"07 November 2023\",\"progress\":0}";
            }
            s_t_i->next();
        }

        while(!j_t_i->isDone()){
            std::shared_ptr<Table> table = std::dynamic_pointer_cast<Table>(j_t_i->currentItem());
            if(table != nullptr){
                to_return += ",{\"name\":\""+ std::to_string(table->getTableID()) +"\",\"status\":\""+ (table->isTableAvailable() == false ? "Assigned" : "Not Assigned") +"\",\"date\":\"07 November 2023\",\"progress\":0}";
            }
            j_t_i->next();
        }

        to_return += "]";
        return to_return;
    }
}



//// line of death

std::string Restaurant::FRONTEND_processCustomerRating(json req_obj) {
    if (req_obj.find("rating") != req_obj.end()) {
        int customerRating = req_obj["rating"];
        return "{\"status\":\"success\",\"message\":\"Thank you for your rating of " + std::to_string(customerRating) + "!\"}";
    } else if (req_obj.find("command") != req_obj.end()) {
        std::string data = req_obj["command"];
        return data;
    } else {
        return "{\"status\":\"error\",\"message\":\"Rating is missing\"}";
    }
}

std::string Restaurant::FRONTEND_processCustomerPayBill(json req_obj) {
    if (req_obj.find("token") != req_obj.end()) {
        if (req_obj.find("command") != req_obj.end()) {
            std::string command = req_obj["command"];
            return command;
        }

        std::string id = req_obj["token"];
        
        if (this->customers.contains(id)) {
            std::shared_ptr<Customer> customer = this->customers[id];
            bool isJoinedTable = customer->getIsSeated(); //please change this to the correct function call
            
            if (isJoinedTable) {
                // Handle bill payment for a joined table and whether split bill or full bill payment here

                this->customers.erase(id);

                std::cout << color::format_colour::make_colour(color::RED) << "Customer with uuid of: " << id << " has paid the bill and left the restaurant" << color::format_colour::make_colour(color::DEFAULT) << std::endl;
                
                return "{\"status\":\"success\",\"message\":\"Customer with uuid " + id + " has paid the bill and left the restaurant\"}";
            } else {
                // Handle bill payment for a single table only single table bill payment here
                
                this->customers.erase(id);
                std::cout << color::format_colour::make_colour(color::RED) << "Customer with uuid of: " << id << " has paid the bill and left the restaurant" << color::format_colour::make_colour(color::DEFAULT) << std::endl;
                
                return "{\"status\":\"success\",\"message\":\"Customer with uuid " + id + " has paid the bill and left the restaurant\"}";
            }
        } else {
            return "{\"status\":\"error\",\"message\":\"Customer not found\"}";
        }
    } else {
        return "{\"status\":\"error\",\"message\":\"Token is missing\"}";
    }
}