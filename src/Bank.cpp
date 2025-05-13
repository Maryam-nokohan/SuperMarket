#include "include/Bank.hpp"
#include <iostream>
BankAccount ::BankAccount(const std :: string & n , const long long unsigned int num , Currency * currency , double limit):AccountName(n),
AccountNumber(num) , Balance(currency) , DailyLimit(limit){}
bool BankAccount :: Deposit(Currency * a){
    *Balance += *a;
    return true;
}
bool BankAccount :: WithDraw(Currency * a){
    if (a->ToUSD() > DailyLimit){
    std :: cout << "Daily limit exceeded!\n";
    return false;}
    else if(a->ToUSD() > Balance->ToUSD())
    {
        std :: cout << "Not enough Balance for Withdraw!\n";
    }
    else{
    *Balance-=*a;
    return true;}

}
Currency * BankAccount :: GetBalance()const{
    return Balance;

}
std :: string BankAccount :: GetAccountName()const{
    return AccountName;
}
BankAccount ::~BankAccount(){
    delete Balance; 
}PersonalAccount :: PersonalAccount(const std :: string & n , const long long unsigned int num , Currency * currency ) : BankAccount(n , num , currency , 1000){}
OrganizationAccount :: OrganizationAccount(const std :: string & n , const long long unsigned int num , Currency * currency ):BankAccount(n , num , currency , 10000){}
