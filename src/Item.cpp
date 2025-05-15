#include "../include/Item.hpp"
#include <iomanip>
#include <stdexcept>
using namespace std;
Item::Item(const std::string& n, double p, double q) : name(n) , price(p) ,quantity(q) {};

string Item::getName() const{ 
    return name;
}
double Item::getPrice() const{
    return price;
}
double Item::getQuantity() const{
    return quantity;
}
int Item::getNumOfPurchas() const{
    return NumOfPurchases;
}
void Item::buy(double value){
    if(value < 0){
        throw invalid_argument("Cannot reduce negative quantity.");
    }
    if(value > quantity){
        throw runtime_error("Not enough quantity available.");
    }
    if(value <= quantity){
        quantity -= value;
    }
}
double Item::Totalprice() const{
    int Total = NumOfPurchases + NumOfPurchases/5 ;
    return Total * price ;
}
Item& Item::operator++(){
    if(quantity > 0){
        NumOfPurchases ++ ;
        quantity -- ;
    }
    return *this;
}

void Item::print(ostream& output) const{
    output << left << setw(15) << name
    << right << setw(6) << quantity 
    << right << setw(10) << price << "$";


}

std::ostream& operator<<(std::ostream& output , const Item& I){
    I.print(output);
    return output;

}
