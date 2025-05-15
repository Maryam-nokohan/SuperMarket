#include "../include/Seasoning.hpp"
#include <iomanip>
using namespace std;

Seasoning::Seasoning(const string& n , double pg , double qg) : Item(n , pg , qg){}

string Seasoning::getUnit() const{
    return "g" ;

}
void Seasoning::print(ostream& output) const{
      output << left << setw(15) << name
    << right << setw(6) << quantity << getUnit()
    << right << setw(10) << price << "$";
}
Item* Seasoning::copy() const{

    return new Seasoning(*this);
}