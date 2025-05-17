#ifndef ITEM_HPP
#define ITEM_HPP

#include <iostream>
#include <string>
class Item
{
friend std::ostream& operator<<(std::ostream& , const Item);
protected:
std::string name;
double price;
double quantity;
int NumOfPurchases = 0;

public:
Item(const std::string& , double , double);
virtual ~Item() = default;
std::string getName() const;
virtual Item* copy() const = 0 ;
double getPrice() const;
double getQuantity() const;
int getNumOfPurchas() const;
virtual std::string getUnit() const = 0 ;
virtual void buy(double);
double Totalprice() const;
virtual void print(std::ostream&) const = 0;
void printReceipt(std::ostream&) const ;
Item& operator++();

};

#endif