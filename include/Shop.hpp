#ifndef SHOP_H
#define SHOP_H
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

class Shop{

    private :
    std :: string UserType;
    public :
    void  CashierSystem( const std::vector<Item*>& cart , PersonalAccount *client , OrganizationAccount * Shop);
    void  CashierSystem( const std::vector<Item*>& cart , OrganizationAccount * client , OrganizationAccount * Shop);

};

#endif