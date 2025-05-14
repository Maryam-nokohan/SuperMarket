#ifndef ITEM_HPP
#define ITEM_HPP

#include <iostream>
#include <string>
class Item
{
friend std::ostream& operator<<(std::ostream& , const Item);
private:
std::string name;
double price;
int quantity;

public:
Item(const std::string& , double , int);
std::string getName() const;
double getPrice() const;
int getQuantity() const;
virtual std::string getUnit() const = 0 ;
virtual void buy(int) = 0 ;
virtual void print(ostream&) const;

};
std::ostream& operator<<(std::ostream& , const Item&);

#endif