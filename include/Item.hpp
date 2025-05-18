#ifndef ITEM_HPP
#define ITEM_HPP

#include <iostream>
#include "../include/Bank.hpp"
#include "../include/Currency.hpp"
#include <string>
#include <vector>
class Item
{
friend std::ostream& operator<<(std::ostream& , const Item &);
protected:
std::string name;
Currency * price;
double quantity;
int NumOfPurchases = 0;

public:
Item(const std::string& , Currency* , double);
virtual ~Item() = default;
void SetPrice(Currency *);
std::string getName() const;
virtual Item* copy() const = 0 ;
Currency* getPrice() const;
double getQuantity() const;
int getNumOfPurchas() const;
virtual std::string getUnit() const = 0 ;
Currency* Totalprice() const;
virtual void print() const = 0;
void printReceipt(std::ostream&) const ;
Item& operator++();

};


#endif