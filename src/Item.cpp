#include "../include/Item.hpp"
#include "../include/USD.hpp"
#include "../include/EUR.hpp"
#include "../include/IRR.hpp"
#include "../include/Currency.hpp"
#include "../include/Bank.hpp"
#include <iomanip>
#include <stdexcept>
#include "../include/errorHandler.hpp"
#include <vector>
#include <memory>

using namespace std;
Item::Item(const std::string &n, Currency* p, double q) : name(n), price(p), quantity(q) {};

string Item::getName() const
{
    return name;
}
Currency *Item::getPrice() const
{
    return price;
}
double Item::getQuantity() const
{
    return quantity;
}
int Item::getNumOfPurchas() const
{
    return NumOfPurchases;
}

Currency* Item::Totalprice() const
{
    int free = NumOfPurchases / 5;
    int payable = NumOfPurchases - free;
    Currency * total = new USD(payable * price->GetAmount());
    return total;
}
Item &Item::operator++()
{
    if (quantity > 0)
    {
        NumOfPurchases++;
        quantity--;
    }
    return *this;
}

void Item::printReceipt(std::ostream &output) const
{
    Currency* total = Totalprice();

    output << "| " 
           << std::setw(16) << std::left << name
           << "| " 
           << std::setw(8) << std::left << std::fixed << std::setprecision(2) << price->GetAmount()  
           << " " 
           << price->GetSymbol()                   
           << " | " 
           << std::setw(6) << std::left << NumOfPurchases    
           << std :: right<< std :: setw(7) << getUnit()                             
           << " | "
           << std::setw(4) << std::right << free      
           << " | "
           << std::setw(8) << std::right << std::fixed << std::setprecision(2) << total->GetAmount()   
           << " " 
           << price->GetSymbol()                     
           << " |\n";
}

std::ostream &operator<<(std::ostream &output, const Item &I)
{
    I.printReceipt(output);
    return output;
}
void Item:: SetPrice(Currency* p){
        price = p;
}
