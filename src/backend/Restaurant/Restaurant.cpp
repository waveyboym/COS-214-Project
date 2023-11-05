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

    this->joined_tables.push_back(std::make_shared<JoinedTable>(1));
    this->joined_tables.push_back(std::make_shared<JoinedTable>(2));
    this->joined_tables.push_back(std::make_shared<JoinedTable>(3));
    this->joined_tables.push_back(std::make_shared<JoinedTable>(4));
    this->joined_tables.push_back(std::make_shared<JoinedTable>(5));
    this->joined_tables.push_back(std::make_shared<JoinedTable>(6));
    this->joined_tables.push_back(std::make_shared<JoinedTable>(7));
    this->joined_tables.push_back(std::make_shared<JoinedTable>(8));
    this->joined_tables.push_back(std::make_shared<JoinedTable>(9));
    this->joined_tables.push_back(std::make_shared<JoinedTable>(10));
    this->joined_tables.push_back(std::make_shared<JoinedTable>(11));
    this->joined_tables.push_back(std::make_shared<JoinedTable>(12));
    this->joined_tables.push_back(std::make_shared<JoinedTable>(14));
    this->joined_tables.push_back(std::make_shared<JoinedTable>(15));
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
    if(random_number % 10 >= 0 && random_number % 10 <=5){
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
        num_seated_customers++;
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
        if (curCustomer != nullptr && curCustomer->getHasCompletedMeal())
        {
            this->maitre_d->unseatCustomer(this->single_tables, this->joined_tables, curCustomer, this->waiters);
            std::cout << color::format_colour::make_colour(color::BLUE) <<"customer with uuid of: " << curCustomer->getUUID() << " has been unseated from the restaurant" << color::format_colour::make_colour(color::DEFAULT) << std::endl;
            this->customers.erase(curCustomer->getUUID());
        }
        c_i->next();
        num_seated_customers--;
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
            // Update the customer's check, dont know how to do this, we are still waiting on backend stuff for this.

            return "{\"status\":\"success\",\"message\":\"Update check successful\"}";
        } else {
            return "{\"status\":\"error\",\"message\":\"Customer not found\"}";
        }
    } else {
        return "{\"status\":\"error\",\"message\":\"Token is missing\"}";
    }
}

//okay so i dont know how to do this, i think its missing a few function calls
std::string Restaurant::FRONTEND_processCustomerOrder(json req_obj) {
    if (req_obj.find("token") != req_obj.end()) {
        std::string id = req_obj["token"];
        if (this->customers.contains(id)) {
            // Extract the order items from the request
            if (req_obj.find("order") != req_obj.end()) {
                json orderItems = req_obj["order"];

                // Process the order items and generate a response
                std::string response = "Order received: ";
                bool firstItem = true;
                for (const auto& item : orderItems) {
                    if (item.find("name") != item.end()) {
                        std::string itemName = item["name"];
                        if (!firstItem) {
                            response += ", ";
                        }
                        response += itemName;
                        firstItem = false;
                    }
                }
 
                return "{\"status\":\"success\",\"message\":\"" + response + "\"}";
            } else {
                return "{\"status\":\"error\",\"message\":\"Order is missing\"}";
            }
        } else {
            return "{\"status\":\"error\",\"message\":\"Customer not found\"}";
        }
    } else {
        return "{\"status\":\"error\",\"message\":\"Token is missing\"}";
    }
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
            else if(emotionalState == "slightlyhappy"){
                curCustomer->setEmotionalState(EMOTIONAL_STATE::SLIGHTLY_HAPPY);
            }
            else if(emotionalState == "slightlyangry"){
                curCustomer->setEmotionalState(EMOTIONAL_STATE::SLIGHTLY_ANGRY);
            }
            else if(emotionalState == "neutral"){
                curCustomer->setEmotionalState(EMOTIONAL_STATE::NEUTRAL);
            }
            else{
                return "{\"status\":\"error\",\"message\":\"no such emotional state exists\"}";
            }

            return "{\"status\":\"success\",\"player\":\"customer\",\"command\":\"change_emotional_state\",\"message\":\"" + emotionalState + "\"}";
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
                to_return += "{\"name\":\""+ curr_customer->getUUID() +"\",\"status\":\""+ (curr_customer->getHasCompletedMeal() == true ? "Assigned" : "Not Assigned") +"\",\"date\":\"" + curr_customer->getCurrentEmotionalStateString() + "\",\"progress\":0}";
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