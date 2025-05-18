#include "../include/Bank.hpp"
#include "../include/Currency.hpp"
#include "../include/USD.hpp"
#include "../include/EUR.hpp"
#include "../include/IRR.hpp"
#include "../include/Item.hpp"
#include "../include/Fruit.hpp"
#include "../include/Seasoning.hpp"
#include "../include/Snack.hpp"
#include "../include/errorHandler.hpp"
#include "../include/Shop.hpp"
#include <iostream>
#include <vector>
using namespace std;

int main()
{

    Shop Markler;
    // Item in shops:
    Item *apple = new Fruit("apple", new USD(1.5), 10);
    Item *Chips = new Snack("Chips", new USD(1.5), 10);
    Item *salt = new Seasoning("slat", new USD(1.5), 10);
    // Item in receipt for Mary:
    vector<Item *> cart1;
    cart1.push_back(apple->copy());
    cart1.push_back(Chips->copy());
    cart1.push_back(salt->copy());
    ++(*cart1[0]);
    ++(*cart1[0]);
    ++(*cart1[0]);
    ++(*cart1[1]);
    ++(*cart1[1]);
    ++(*cart1[1]);
    ++(*cart1[2]);
    ++(*cart1[2]);
    // Item in receipt for Saba:
    vector<Item *> cart2;
    cart2.push_back(apple->copy());
    cart2.push_back(Chips->copy());
    cart2.push_back(salt->copy());
    ++(*cart2[0]);
    ++(*cart2[0]);
    ++(*cart2[0]);
    ++(*cart2[0]);
    ++(*cart2[0]);
    ++(*cart2[0]);
    ++(*cart2[0]);
    ++(*cart2[1]);
    ++(*cart2[1]);
    ++(*cart2[1]);
    ++(*cart2[1]);
    ++(*cart2[2]);
    ++(*cart2[2]);
    ++(*cart2[2]);
    ++(*cart2[2]);
    // Creating Currency for accounts :
    Currency *c1 = new USD(122.7);
    Currency *c2 = new IRR(122000000.7);
    Currency *c3 = new EUR(12.8);
    // Creating bank Accounts :
    PersonalAccount *mary = new PersonalAccount("mary", "123456789", c2);
    OrganizationAccount *saba = new OrganizationAccount("saba" , "1111111111333" ,c3 );
    OrganizationAccount *Shop = new OrganizationAccount("SuperMarket", "1111111111", c1);
    // Chashier Helper System :
    Markler.CashierSystem(cart1, mary, Shop);
    Markler.CashierSystem(cart2, saba, Shop);

    cart1.clear();
    cart2.clear();
    delete c1;
    delete c2;
    delete c3;
    delete saba;
    delete mary;
    delete Shop;
    return 0;
}