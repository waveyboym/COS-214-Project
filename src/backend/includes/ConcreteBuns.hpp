/**
*@file ConcreteBuns.hpp ConcreteBuns.cpp 
*@author Jaide
*@brief File containing all Concrete Bun classes
*/
#ifndef CONCRETE_BUNS_HPP
#define CONCRETE_BUNS_HPP
#include "Bun.hpp"

/** @defgroup Buns
 *  The group of concrete buns - the concrete components of the meal class
 *  @{
 */

/** @brief class NoBun in group Buns*/
class NoBun: public Bun{
    public:
        /**
        * @brief constructor
        * @param none
        */
        NoBun();
        /**
        * @brief returns an itemized string list of this bun
        * @param none
        * @return std::string
        */
        std::string getItemizedList();
        /**
        * @brief returns an itemized string list of this bun and prepends the passed in string
        * @param none
        * @return std::string
        */
        std::string getItemizedList(std::string s);
};

/** @brief class PlainBun in group Buns*/
class PlainBun: public Bun{
    public:
        /**
        * @brief constructor
        * @param none
        */
        PlainBun();
};

/** @brief class WholewheatBun in group Buns*/
class WholewheatBun: public Bun{
    public:
        /**
        * @brief constructor
        * @param none
        */
        WholewheatBun();
};

/** @} */ // end of Buns

#endif