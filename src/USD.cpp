#include "../include/USD.hpp"
std ::string USD::GetSymbol() const
{
    return Symbol;
}
double USD::ToUSD() const
{
    return amount;
}
double USD::FromUSD(double usd)
{
    return usd;
}
double USD::ToEUR() const
{
    return amount * 0.9;
}
double USD::ToIRR() const
{
    return amount * 82000;
}