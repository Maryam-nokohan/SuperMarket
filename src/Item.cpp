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
    int free = NumOfPurchases/5 ;
    int payable = NumOfPurchases - free ;
    return payable * price;
}
Item& Item::operator++(){
    if(quantity > 0){
        NumOfPurchases ++ ;
        quantity -- ;
    }
    return *this;
}

    void Item::printReceipt(ostream& output) const {
    int free = NumOfPurchases/ 5;
    int payable = NumOfPurchases - free;
    double total = Totalprice();

    output << left << setw(12) << name
       << "|  $" << right << setw(5) << fixed << setprecision(2) << price
       << "  |" << setw(2) << NumOfPurchases << setw(7)<<getUnit()
       << " |" << setw(6) << free
       << "| $" << setw(6) << fixed << setprecision(2) << total
       << endl;
}



std::ostream& operator<<(std::ostream& output , const Item& I){
    I.printReceipt(output);
    return output;

}