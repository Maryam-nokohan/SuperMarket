#ifndef USD_H
#define USD_H
#include "../include/Currency.hpp"
#include <string>
class USD : public Currency
{
private :
std :: string Symbol;
public:
    USD()=default;
    USD(double a = 0.0) : Currency(a) {Symbol = "USD";}
    std ::string GetSymbol() const override;
    double ToUSD() const override;
    double FromUSD(double) override;
    double ToEUR() const override;
    double ToIRR() const override;
    virtual ~USD(){}
};
#endif