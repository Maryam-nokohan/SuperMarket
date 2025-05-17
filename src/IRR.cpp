#include "../include/IRR.hpp"
std ::string IRR::GetSymbol() const
{
    return Symbol;
}
double IRR::FromUSD(double irr)
{
    return irr * 82000;
}
double IRR::ToUSD() const
{
    return amount / 82000;
}
double IRR::ToEUR()const
{
    return amount / 91000;
}
double IRR::ToIRR()const
{
    return amount;
}