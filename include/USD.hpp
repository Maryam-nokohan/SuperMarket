#ifndef USD_H
#define USD_H
#include "../include/Currency.hpp"
class USD : public Currency
{

public:
    USD(double a = 0.0) : Currency(a) {};
    std ::string GetSymbol() const override;
    double ToUSD() const override;
    double FromUSD(double);
};
#endif