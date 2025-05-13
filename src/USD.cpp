#include "include/USD.hpp"
    std ::string USD:: GetSymbol() const{
        return "USD";

    }
    double USD:: ToUSD() const{
        return amount;

    }
    double USD:: FromUSD(double usd)
    {
        return usd;
    }