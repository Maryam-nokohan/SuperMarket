#ifndef BANK_H
#define BANK_H
#include "../include/Currency.hpp"
class BankAccount
{
protected:
    std ::string AccountName;
    std ::string AccountNumber;
    Currency *Balance;
    double DailyLimit;

public:
    BankAccount() {}
    BankAccount(std ::string n, std ::string num, Currency *a, int d);
    virtual ~BankAccount();
    void Deposit(Currency *a);
    void WithDraw(Currency *a);
    Currency *GetBalance() const;
    std ::string GetAccountName() const;
};
class PersonalAccount : public BankAccount
{
public:
    PersonalAccount(const std ::string &n, const std ::string num, Currency *currency);
};
class OrganizationAccount : public BankAccount
{
public:
    OrganizationAccount(const std ::string &n, const std ::string num, Currency *currency);
};

#endif