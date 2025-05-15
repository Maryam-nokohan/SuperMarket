#ifndef FRUIT_HPP
#define FRUIT_HPP
#include "Item.hpp"
class Fruit : public Item {
    public:
    Fruit(const std::string& , double , double );
    std::string getUnit() const override ;
    Item* copy() const override;
    void print(std::ostream&) const override;

};
#endif