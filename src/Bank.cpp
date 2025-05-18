#include "../include/Bank.hpp"
#include <iostream>
#include <stdexcept>
#include "../include/Currency.hpp"
#include "../include/errorHandler.hpp"
#include "../include/EUR.hpp"
#include "../include/IRR.hpp"
#include "../include/USD.hpp"
#include "stdexcept"
BankAccount ::BankAccount(std ::string n, std ::string num, Currency *a, int d) : AccountName(n), AccountNumber(num), Balance(a), DailyLimit(d) {}
void BankAccount ::Deposit(Currency *a)
{    
    *Balance += *a;
}
void BankAccount ::WithDraw(Currency *a)
{
   
    if(DailyTranssformed + a->ToUSD() > DailyLimit)
    {  
        std :: cout << "You want to transfor : "<<DailyTranssformed + a->ToUSD() <<" USD and the daily limit is : "<<DailyLimit <<'\n';
        throw std ::invalid_argument("Daily limit exceeded!\n");
    }
    else if (a->ToUSD() > Balance->ToUSD())
    {
        throw std ::invalid_argument("Not enough Balance for Withdraw!\n");
    }
    else
    {
        std :: cout << "WithDraw succsesfully!\n";
        DailyTranssformed += a->ToUSD();
        *Balance -= *a;
    }
}
Currency *BankAccount ::GetBalance() const
{
    return Balance;
}
std ::string BankAccount ::GetAccountName() const
{
    return AccountName;
}
BankAccount ::~BankAccount()
{
    delete Balance;
}
PersonalAccount ::PersonalAccount(const std ::string &n, std ::string num, Currency *currency) : BankAccount(n, num, currency, 1000) {}
OrganizationAccount ::OrganizationAccount(const std ::string &n, std ::string num, Currency *currency) : BankAccount(n, num, currency, 10000) {}
