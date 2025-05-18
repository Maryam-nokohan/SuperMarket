#ifndef IRR_H
#define IRR_H
#include "../include/Currency.hpp"
#include <string>
class IRR : public Currency{
    private :
    std :: string Symbol;
    public :
    IRR()=default;
    IRR(double a = 0.0): Currency(a) {Symbol ="IRR";}
    std ::string GetSymbol() const override;
    double ToUSD() const override;
    double FromUSD(double)override;
    double ToEUR() const override;
    double ToIRR() const override;
    virtual ~IRR(){}
};
#endif