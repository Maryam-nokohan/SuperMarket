#include "include/Currency.hpp"
#include <string>
  double Currency:: GetAmount() const{
    return amount;
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