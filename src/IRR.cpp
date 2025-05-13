#include "include/IRR.hpp"
std ::string IRR::GetSymbol() const
{
    return "IRR";
}
double IRR::ToUSD() const
{
    return amount * 0.000024;
}
double IRR::FromUSD(double irr)
{
    return irr / 0.000024;
}