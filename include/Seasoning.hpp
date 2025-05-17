#ifndef SEASONING_HPP
#define SEASONING_HPP
#include "Item.hpp"
#include "../include/Currency.hpp"
class Seasoning : public Item{
    public:
    Seasoning(const std::string& ,Currency* , double);
    std::string getUnit() const override;
    void print(std::ostream&) const override;
    Item* copy() const override;

};
#endif