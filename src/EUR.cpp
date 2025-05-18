#include "../include/EUR.hpp"
std ::string EUR::GetSymbol() const
{
    return Symbol;
}
double EUR::ToUSD() const
{
    return amount * 1.11;
}
double EUR::FromUSD(double eur)
{
    return eur / 1.11;
}
double EUR::ToIRR()const{
    return amount *91000;
}
double EUR::ToEUR()const{
    return amount;
}