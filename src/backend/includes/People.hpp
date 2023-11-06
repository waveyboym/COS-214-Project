/**
*@file People.hpp People.cpp
*@class People
*@implements Collectable
*@author Michael
*@brief a People class which is a concrete iterator class of Collectable
*/
#ifndef PEOPLE_HPP
#define PEOPLE_HPP
#include "Collectable.hpp"
#include <string>

/**
*@brief a People class which is a concrete iterator class of Collectable
*/
class People : public Collectable{
    protected:
        /**
        *@brief the uuid of this person
        */
        std::string person_uuid;
    public:
        /** 
        *@brief a null function to allow for polymorphic features to be used
        *@param none
        *@return void
        */
        void nill();

        //TODO: implement
        virtual bool personAction() = 0;

        /** 
        *@brief gets the uuid of this person
        *@param none
        *@return std::string
        */ 
        std::string getUUID();
        
        /** 
        *@brief sets the uuid of this person
        *@note this uuid should only be set once when this person is created
        *@param set_to uuid to set to
        *@return void
        */ 
        void setUUID(std::string set_to);
};

#endif