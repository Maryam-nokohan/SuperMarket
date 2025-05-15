#include "../include/Snack.hpp"
#include <iomanip>
using namespace std;
<<<<<<< Updated upstream
Snack::Snack(const string& n , double pp , double qp) : Item(n , pp , qp){};

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
=======

Snack::Snack(const string& n , double pp, double qp) : Item(n , pp , qp){}

string Snack::getUnit() const{
    return "pkg" ;

}
void Snack::print(ostream& output) const{
    output << name <<" - " << price <<" per "<< getUnit();
}
Item* Snack::copy() const{

    return new Snack(*this);
>>>>>>> Stashed changes
}