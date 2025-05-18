#include "../include/Fruit.hpp"
#include <iomanip>
#include "../include/Currency.hpp"
using namespace std;
Fruit::Fruit(const string& n , Currency* pkg , double qkg) : Item(n , pkg , qkg){};
string Fruit::getUnit() const{
    return "kg" ;
}
Item* Fruit::copy() const{
    return new Fruit(*this);
}
void Fruit::print() const{
     std :: cout << left << setw(15) << name
    << right << setw(6) << quantity << getUnit()
    << right << setw(10) << price->GetAmount() << price->GetSymbol();
}