#include "../includes/Restaurant.hpp"

Restaurant::Restaurant(){
    this->maitre_d = std::make_shared<ConcreteMaitreD>();
    
}

Restaurant::~Restaurant(){

}

std::shared_ptr<Restaurant> Restaurant::instance(){
    static std::shared_ptr<Restaurant> restaurant_object{new Restaurant};
    return restaurant_object;
}

std::string Restaurant::processCustomerOrder(json req_obj){
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

std::string Restaurant::processCustomersEmotion(json req_obj){
    std::string data = req_obj["emotional_state"];
    return data;
}

std::string Restaurant::processUpdateCheck(json req_obj){
    std::string data = req_obj["token"];
    return data;
}