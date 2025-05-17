#ifndef EUR_H
#define EUR_H
#include "../include/Currency.hpp"
#include <string>
class EUR : public Currency{
    private :
    std :: string Symbol;
    public :
    EUR()=default;
    EUR(double a = 0.0): Currency(a) {Symbol ="EUR";}
    std ::string GetSymbol() const override;
    double ToUSD() const override;
    double FromUSD(double);
    double ToEUR() const ;
    double ToIRR() const;
    virtual ~EUR(){}
};
#endif