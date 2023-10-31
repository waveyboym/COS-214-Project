#include "../includes/People.hpp"

void People::nill(){}

std::string People::getUUID(){
    return this->person_uuid;
}

void People::setUUID(std::string set_to){
    this->person_uuid = set_to;
}