#ifndef IRR_H
#define IRR_H
#include "../include/Currency.hpp"
class IRR : public Currency
{
public:
    IRR(double a = 0.0) : Currency(a) {};
    std ::string GetSymbol() const override;
    double ToUSD() const override;
    double FromUSD(double);
};
#endif