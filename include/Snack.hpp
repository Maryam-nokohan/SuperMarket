#ifndef SNACK_HPP
#define SNACK_HPP
#include "Item.hpp"
#include "../include/Currency.hpp"
class Snack : public Item{
    public:
    Snack(const std::string&, Currency * , double);
    std::string getUnit() const override ;
    void print(std::ostream&) const override;
    Item* copy() const override ;

};
#endif