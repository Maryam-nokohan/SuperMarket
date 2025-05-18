#ifndef FRUIT_HPP
#define FRUIT_HPP
#include "Item.hpp"
#include "../include/Fruit.hpp"
class Fruit : public Item {
    public:
    Fruit(const std::string& , Currency* , double );
    std::string getUnit() const override ;
    Item* copy() const override;
    void print() const override;

};
#endif