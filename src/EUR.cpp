#include "include/EUR.hpp"
std ::string EUR::GetSymbol() const
{
    return "EUR";
}
double EUR::ToUSD() const
{
    return amount * 1.11;
}
double EUR::FromUSD(double eur)
{
    return eur / 1.11;
}