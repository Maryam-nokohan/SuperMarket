#include "../include/Item.hpp"
#include "../include/USD.hpp"
#include "../include/EUR.hpp"
#include "../include/IRR.hpp"
#include "../include/Currency.hpp"
#include "../include/Bank.hpp"
#include <iomanip>
#include <stdexcept>
#include "../include/errorHandler.hpp"
#include <vector>
#include <memory>

using namespace std;
Item::Item(const std::string &n, Currency* p, double q) : name(n), price(p), quantity(q) {};

string Item::getName() const
{
    return name;
}
Currency *Item::getPrice() const
{
    return price;
}
double Item::getQuantity() const
{
    return quantity;
}
int Item::getNumOfPurchas() const
{
    return NumOfPurchases;
}

double Item::Totalprice() const
{
    int free = NumOfPurchases / 5;
    int payable = NumOfPurchases - free;
    return payable * price->GetAmount();
}
Item &Item::operator++()
{
    if (quantity > 0)
    {
        NumOfPurchases++;
        quantity--;
    }
    return *this;
}

void Item::printReceipt(ostream &output) const
{
    int free = NumOfPurchases / 5;
    int payable = NumOfPurchases - free;
    double total = Totalprice();
    output << left << setw(20) << name << "|" << left << setw(10) << fixed << setprecision(2) << price->GetAmount() << price->GetSymbol()
           << "  |" << setw(2) << NumOfPurchases << setw(7) << getUnit()
           << " |" << setw(6) << free
           << "|" << price->GetSymbol() << setw(6) << fixed << setprecision(2) << total
           << endl;
}

std::ostream &operator<<(std::ostream &output, const Item &I)
{
    I.printReceipt(output);
    return output;
}
void Item:: SetPrice(Currency* p){
        price = p;
}
#include <memory> // Add this include at the top

void InputItems(const std::vector<Item*>& cart, PersonalAccount* client, OrganizationAccount* Shop) {
    string symbol;
    string CurrencyMenu = R"(
    Please Select Your Client Currency :
    1.USD
    2.EUR
    3.IRR
    4.Enter :)";
    cout << CurrencyMenu;
    double TotalPrice = 0;
    string option;
    getline(cin, option);
    // if(CheckInt(option));
    
    cout << "---------------------------Thanks for shopping in the Marklar Supermarket!---------------------------\n";
    
    if(stoi(option) == 1) {
        for(const auto& item : cart) {
            cout << *item;
        }   
        for(const auto& item : cart) {
            TotalPrice += item->Totalprice();
        }
        cout << "------------------------------------\n";
        cout << "Total Price :" << TotalPrice << " USD\n";
        
        std::unique_ptr<Currency> Total(new USD(TotalPrice));
        client->WithDraw(Total.get());
        Shop->Deposit(Total.get());
    }
    else if(stoi(option) == 2) {
        for(const auto& item : cart) {
            std::unique_ptr<Currency> tempPrice(new EUR(item->getPrice()->ToEUR()));
            item->SetPrice(tempPrice.get());
            cout << *item;
            TotalPrice += item->Totalprice();
        }
        cout << "------------------------------------\n";
        cout << "Total Price :" << TotalPrice << " EUR\n";
        
        std::unique_ptr<Currency> Total(new EUR(TotalPrice));
        client->WithDraw(Total.get());
        std::unique_ptr<Currency> shopDeposit(new USD(Total->ToUSD()));
        Shop->Deposit(shopDeposit.get());
    }
    else if(stoi(option) == 3) {
        for(const auto& item : cart) {
            std::unique_ptr<Currency> tempPrice(new IRR(item->getPrice()->ToIRR()));
            item->SetPrice(tempPrice.get());
            cout << *item;
            TotalPrice += item->Totalprice();
        }
        cout << "------------------------------------\n";
        cout << "Total Price :" << TotalPrice << " IRR\n";
        
        std::unique_ptr<Currency> Total(new IRR(TotalPrice));
        client->WithDraw(Total.get());
        std::unique_ptr<Currency> shopDeposit(new USD(Total->ToUSD()));
        Shop->Deposit(shopDeposit.get());
    }
    else {
        throw invalid_argument("Out of range\n");
    }
}