#include "../includes/Restaurant.hpp"
/*@note for any function that starts with FRONTEND, you are not allowed to edit it if you are not working on frontend*/

Restaurant::Restaurant(){
    this->maitre_d = std::make_shared<ConcreteMaitreD>();
    this->frontend_manager_table_type = "waiters";
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
    if(random_number % 10 >= 0 && random_number % 10 <= 7){
        //unseat customers who are done with their order and erase them from the customer map

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
        if (curCustomer->getHasCompletedMeal())
        {
            this->maitre_d->unseatCustomer(this->single_tables, this->joined_tables, curCustomer, this->waiters);
            std::cout << color::format_colour::make_colour(color::BLUE) <<"customer with uuid of: " << curCustomer->getUUID() << " has been unseated from the restaurant" << color::format_colour::make_colour(color::DEFAULT) << std::endl;
            this->customers.erase(curCustomer->getUUID());
        }
        c_i->next();
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

std::string Restaurant::FRONTEND_processCustomerOrder(json req_obj){
    std::vector<std::string> orders_items;
    for (auto& elem : req_obj["order"]){
        orders_items.push_back(elem["name"]);
    }

    std::string data = "";
    for(int i = 0; i < orders_items.size(); ++i){
        if(i == orders_items.size() - 1){
            data += orders_items[i];
        }
        else{
            data += orders_items[i] + ",";
        }
    }
    return data;
}

std::string Restaurant::FRONTEND_processCustomersEmotion(json req_obj){
    std::string data = req_obj["emotional_state"];
    return data;
}

std::string Restaurant::FRONTEND_processUpdateCheck(json req_obj){
    std::string data = req_obj["token"];
    return data;
}

std::string Restaurant::FRONTEND_processManagerGetAll(json req_obj){
    if(this->frontend_manager_table_type == "waiters"){
        return "{"
                    "\"status\":\"success\","
                    "\"player\":\"manager\","
                    "\"command\":\"get_all\","
                    "\"message\":{"
                        "\"customer_count\":"+ std::to_string(this->customers.size()) +","
                        "\"waiter_count\":"+ std::to_string(this->waiters.size()) +","
                        "\"rating\":5"
                    "},"
                    "\"table_data\":["
                        + this->FRONTEND_getTableObjects("waiters") +
                    "]"
                "}";
    }
    else if(this->frontend_manager_table_type == "customers"){
        return "{"
                    "\"status\":\"success\","
                    "\"player\":\"manager\","
                    "\"command\":\"get_all\","
                    "\"message\":{"
                        "\"customer_count\":"+ std::to_string(this->customers.size()) +","
                        "\"waiter_count\":"+ std::to_string(this->waiters.size()) +","
                        "\"rating\":5"
                    "},"
                    "\"table_data\":["
                        + this->FRONTEND_getTableObjects("customers") +
                    "]"
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
                    "\"table_data\":["
                        + this->FRONTEND_getTableObjects("tables") +
                    "]"
                "}";
    }
}

std::string Restaurant::FRONTEND_processManagerGetTable(json req_obj){
    std::string table_type_ = req_obj["table_type"];
    this->frontend_manager_table_type = table_type_;
    if(this->frontend_manager_table_type == "waiters"){
        return "{"
                "\"status\":\"success\","
                "\"player\":\"manager\","
                "\"command\":\"update_table\","
                "\"table_data\":" + this->FRONTEND_getTableObjects("waiters") +
            "}";
    }
    else if(this->frontend_manager_table_type == "customers"){
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

std::string Restaurant::FRONTEND_processCheckOutCustomer(json req_obj){
    return "{\"status\":\"success\",\"player\":\"customer\",\"bill\":2000}";
}

std::string Restaurant::FRONTEND_processCustomerRating(json req_obj){
    std::string data = req_obj["command"];
    return data;
}

std::string Restaurant::FRONTEND_processCustomerPayBill(json req_obj){
    std::string data = req_obj["command"];
    return data;
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
    return "{\"status\":\"error\",\"message\":\"player does not exist\"}";
}

std::string Restaurant::FRONTEND_processCustomerRequestSeat(json req_obj){
    std::string id = req_obj["token"];
    if(this->customers.contains(id)){
        this->maitre_d->seatCustomer(this->single_tables, this->joined_tables, this->customers[id]);
        std::cout << color::format_colour::make_colour(color::BLUE) <<"customer with uuid of: " << id << " has been seated in the restaurant" << color::format_colour::make_colour(color::DEFAULT) << std::endl;
        return "{\"status\":\"success\",\"player\":\"customer\",\"command\":\"seat_request\",\"message\":\"seated\"}";
    }
    return "{\"status\":\"error\",\"message\":\"player does not exist\"}";
}

std::string Restaurant::FRONTEND_processCustomerRequestUnSeat(json req_obj){
    std::string id = req_obj["token"];
    if(this->customers.contains(id)){
        this->maitre_d->unseatCustomer(this->single_tables, this->joined_tables, this->customers[id], this->waiters);
        std::cout << color::format_colour::make_colour(color::BLUE) <<"customer with uuid of: " << id << " has been unseated in the restaurant" << color::format_colour::make_colour(color::DEFAULT) << std::endl;
        return "{\"status\":\"success\",\"player\":\"customer\",\"command\":\"unseat_request\",\"message\":\"unseated\"}";
    }
    return "{\"status\":\"error\",\"message\":\"player does not exist\"}";
}
