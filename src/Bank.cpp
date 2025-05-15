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
/* BankAccount* PersonalAccount:: BankRegisterSystem()
{
    std ::cout << "--------------Welcome to bank register system--------------\n";
    std ::cout << "Please Enter your account name : ";
    std ::getline(std ::cin, AccountName);
    if (CheckString(AccountName))
        ;
    std ::cout << "Please Enter your Account Number : ";
    std ::getline(std ::cin, AccountNumber);
    if (CheckInt(AccountNumber))
        ;
    std ::string ChoosenOption;
    std ::string menu = R"(
    Please select your Currency :
    1.USD
    2.IRR
    3.EUR
    Select a number : )";
    std ::cout << menu;
    getline(std ::cin, ChoosenOption);
    if (CheckInt(ChoosenOption))
        ;
    switch (stoi(ChoosenOption))
    {
    case 1:
        Balance = new USD(0.0);
        break;
    case 2:
        Balance = new IRR(0.0);
        break;
    case 3:
        Balance = new EUR(0.0);
        break;

    default:
        throw std ::invalid_argument("out of range number!!\n");
        break;
    }
    std :: cout << "How much would you like to investigate in our Bank ? : ";
    std :: string investment;
    getline(std :: cin , investment);
    if(CheckFloat(investment));
    Balance->SetAmount(stod(investment));
    menu = R"(
    Would you like to open a persoanl or Organization Account?
    1.Personal Account
    2.Organization Account
    Select a option: )";
    std :: cout << menu;
    getline(std :: cin ,ChoosenOption);
    if(CheckInt(ChoosenOption));
    switch (stoi(ChoosenOption))
    {
    case 1:{
    PersonalAccount* temp = new PersonalAccount(AccountName,AccountNumber,Balance);
    return temp;}
    case 2:{
    OrganizationAccount* temp = new OrganizationAccount(AccountName , AccountNumber , Balance);
    return temp;}
    default:
        throw std ::invalid_argument("out of range number!!\n");
        break;
    }

} */
void BankAccount ::Deposit(Currency *a)
{
    *Balance += *a;
}
void BankAccount ::WithDraw(Currency *a)
{
    if (a->ToUSD() > DailyLimit)
    {
        throw std ::invalid_argument("Daily limit exceeded!\n");
    }
    else if (a->ToUSD() > Balance->ToUSD())
    {
        throw std ::invalid_argument("Not enough Balance for Withdraw!\n");
    }
    else
    {
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
