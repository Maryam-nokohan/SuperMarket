#include "../include/Snack.hpp"
#include <iomanip>
#include "../include/Currency.hpp"
using namespace std;
Snack::Snack(const string& n , Currency* pp , double qp) : Item(n , pp , qp){};

string Snack::getUnit() const{
    return "package" ;
}
void Snack::print(ostream& output) const{
    output<< left << setw(15) << name 
    << right << setw(6) << quantity << getUnit()
    << right << setw(10) << price << "$" ;
}
Item* Snack::copy() const {
    return new Snack(*this) ;
}