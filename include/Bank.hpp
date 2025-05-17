#ifndef BANK_H
#define BANK_H
#include "../include/Currency.hpp"
#include <ctime>
#include <iostream>
class BankAccount
{
protected:
    std ::string AccountName;
    std ::string AccountNumber;
    Currency *Balance;
    double DailyLimit;
    double DailyTranssformed = 0.0;
    public:
    
    BankAccount()=default;
    BankAccount(std ::string n, std ::string num, Currency *a, int d);
    virtual ~BankAccount();
    void Deposit(Currency *a);
    void WithDraw(Currency *a);
    Currency *GetBalance() const;
    std ::string GetAccountName() const;
};
class PersonalAccount : public BankAccount
{
    private:
    public:
    PersonalAccount()=default;
    virtual ~PersonalAccount(){}
    PersonalAccount(const std ::string &n, const std ::string num, Currency *currency);
};
class OrganizationAccount : public BankAccount
{
    private:
    public:
    virtual ~OrganizationAccount(){}
    OrganizationAccount()=default;
    OrganizationAccount(const std ::string &n, const std ::string num, Currency *currency);
};

#endif