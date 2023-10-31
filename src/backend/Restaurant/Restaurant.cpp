#include "../includes/Restaurant.hpp"

Restaurant::Restaurant(){
    this->maitre_d = std::make_shared<ConcreteMaitreD>();
    
}