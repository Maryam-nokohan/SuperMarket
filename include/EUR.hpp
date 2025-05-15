#ifndef EUR_H
#define EUR_H
#include "../include/Currency.hpp"
class EUR : public Currency{
    public :
    EUR(double a = 0.0): Currency(a) {};
    std ::string GetSymbol() const override;
    double ToUSD() const override;
    double FromUSD(double);
};
#endif