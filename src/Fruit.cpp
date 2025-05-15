#include "../include/Fruit.hpp"
#include <iomanip>
using namespace std;
Fruit::Fruit(const string& n , double pkg , double qkg) : Item(n , pkg , qkg){};
string Fruit::getUnit() const{
    return "kg" ;
}
Item* Fruit::copy() const{
    return new Fruit(*this);
}
void Fruit::print(ostream& output) const{
     output << left << setw(15) << name
    << right << setw(6) << quantity << getUnit()
    << right << setw(10) << price << "$";


}