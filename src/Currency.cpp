#include "../include/Currency.hpp"
#include <string>
#include <stdexcept>
void Currency:: SetAmount(double a){
    if(a < 0)
    throw std ::invalid_argument("Negative number aren't availiable for Balance!\n");
    amount = a;
}
  double Currency:: GetAmount() const{
    return amount;
  }
Currency :: Currency(double a){
    SetAmount(a);
}

  
Currency &Currency ::operator+=(const Currency &currency)
{
    amount += currency.ToUSD();
    return *this;
}
Currency &Currency ::operator-=(const Currency &currency)
{
    amount -= currency.ToUSD();
    return *this;
}
Currency &Currency ::operator*=(const Currency &currency)
{
    amount *= currency.ToUSD();
    return *this;
}
Currency &Currency ::operator/=(const Currency &currency)
{
    amount /= currency.ToUSD();
    return *this;
}
bool Currency ::operator==(const Currency &currency)
{
    return currency.ToUSD() == ToUSD();
}
bool Currency ::operator!=(const Currency &currency)
{
    return currency.ToUSD() != ToUSD();
}
bool Currency ::operator>(const Currency &currency)
{
    return currency.ToUSD() > ToUSD();
}
bool Currency ::operator<(const Currency &currency)
{
    return currency.ToUSD() < ToUSD();
}