#ifndef CURRENCY_H
#define CURRENCY_H
#include <string>
class Currency
{
    // friend std ::ostream &operator<<(std ::ostream &output, const Currency &);
    // friend std ::istream &operator>>(std ::istream &input, Currency &);

protected:
    double amount;

public:
    Currency(double a = 0.0) : amount(a) {}
    virtual std ::string GetSymbol() const = 0;
    double GetAmount() const;
    virtual double ToUSD() const = 0;
    virtual double FromUSD(double) = 0;
    Currency &operator+(const Currency &);
    Currency &operator-(const Currency &);
    Currency &operator*(const Currency &);
    Currency &operator/(const Currency &);
    bool operator==(const Currency &);
    bool operator!=(const Currency &);
    bool operator>(const Currency &);
    bool operator<(const Currency &);
    virtual ~Currency(){};
};

#endif