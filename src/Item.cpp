#include "../include/Item.hpp"
#include <iomanip>
using namespace std;
Item::Item(const std::string& n, double p, int q) : name(n) , price(p) ,quantity(q) {};

string Item::getName() const{ 
    return name;
}
double Item::getPrice() const{
    return price;
}
int Item::getQuantity() const{
    return quantity;
}

void Item::print(ostream& output) const{
    output << left << setw(15) << name
    << right << setw(6) << quantity 
    << right << setw(10) << price ;


}

std::ostream& operator<<(std::ostream& output , const Item& I){
    I.print(output);
    return output;

}
