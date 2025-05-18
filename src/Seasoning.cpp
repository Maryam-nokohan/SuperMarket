#include "../include/Seasoning.hpp"
#include <iomanip>
#include "../include/Currency.hpp"
using namespace std;

Seasoning::Seasoning(const string& n , Currency* pg , double qg) : Item(n , pg , qg){}

string Seasoning::getUnit() const{
    return "g" ;

}
void Seasoning::print() const{
      std :: cout << left << setw(15) << name
    << right << setw(6) << quantity << getUnit()
    << right << setw(10) <<  price->GetAmount() << price->GetSymbol();
}
Item* Seasoning::copy() const{

    return new Seasoning(*this);
}