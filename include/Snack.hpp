#ifndef SNACK_HPP
#define SNACK_HPP
#include "Item.hpp"
class Snack : public Item{
    public:
<<<<<<< Updated upstream
    Snack(const std::string&, double , double);
    std::string getUnit() const override ;
    void print(std::ostream&) const override;
    Item* copy() const override ;
=======
    Snack(const std::string& , double , double);
    std::string getUnit() const override;
    void print(std::ostream&) const override;
    Item* copy() const override;
>>>>>>> Stashed changes

};
#endif