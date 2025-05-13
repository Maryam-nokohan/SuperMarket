#ifndef BANK_H
#define BANK_H
#include "include/Currency.hpp"
class BankAccount
{
private:
std :: string AccountName;
long long unsigned int AccountNumber;
Currency * Balance;
double DailyLimit;
public:
BankAccount(const std :: string & n , const long long unsigned int num , Currency * currency , double limit);
virtual ~BankAccount();
bool Deposit(Currency * a);
bool WithDraw(Currency * a);
Currency * GetBalance()const;
std :: string GetAccountName()const;
};
class PersonalAccount : public BankAccount{
    public :
    PersonalAccount(const std :: string & n , const long long unsigned int num , Currency * currency );

};
class OrganizationAccount : public  BankAccount{
OrganizationAccount(const std :: string & n , const long long unsigned int num , Currency * currency );
};

#endif