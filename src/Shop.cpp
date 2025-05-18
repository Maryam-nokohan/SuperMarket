#include "../include/Item.hpp"
#include "../include/Fruit.hpp"
#include "../include/Seasoning.hpp"
#include "../include/Snack.hpp"
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
#include "../include/Shop.hpp"

void Shop::CashierSystem(const std::vector<Item *> &cart, PersonalAccount *client, OrganizationAccount *Shop)
{

    std ::string ClientCurrency = client->GetBalance()->GetSymbol();
    std ::string ShopCurrency = Shop->GetBalance()->GetSymbol();

    std::cout << "\n==========================================\n";
    std::cout << "       Marklar Supermarket Receipt       \n";
    std::cout << "==========================================\n";
    std::cout << "| Item Name        | Price       | Qty           | Free | Total        |\n";
    std::cout << "------------------------------------------------------------------------\n";
    Currency * TotalPrice = nullptr;

    if(ClientCurrency == "USD")
    TotalPrice = new USD(0.0);
    else if(ClientCurrency == "IRR")
    TotalPrice = new IRR(0.0);
    else if(ClientCurrency == "EUR")
    TotalPrice = new EUR(0.0);


    for (const auto &item : cart)
    {
        if (ClientCurrency == "EUR")
            item->SetPrice(new EUR(item->getPrice()->ToEUR()));
        else if (ClientCurrency == "IRR")
            item->SetPrice(new IRR(item->getPrice()->ToIRR()));
        std ::cout << *item;
        *TotalPrice += *item->Totalprice();
    }

    std ::cout << "------------------------------------\n";
    std ::cout << "Total Price = " << TotalPrice->GetAmount() <<'\n';
    client->WithDraw(TotalPrice);

    if (ShopCurrency == "IRR")
        Shop->Deposit(new IRR(TotalPrice->ToIRR()));
    else if (ShopCurrency == "USD")
        Shop->Deposit(new IRR(TotalPrice->ToEUR()));
    else if (ShopCurrency == "EUR")
        Shop->Deposit(new IRR(TotalPrice->ToUSD()));
        std :: cout << "Shop has a total of ="<<Shop->GetBalance()->GetAmount() << " " << Shop->GetBalance()->GetSymbol()<<'\n';
        delete TotalPrice;
}

void Shop::CashierSystem(const std::vector<Item *> &cart, OrganizationAccount *client, OrganizationAccount *Shop)
{

   
    std ::string ClientCurrency = client->GetBalance()->GetSymbol();
    std ::string ShopCurrency = Shop->GetBalance()->GetSymbol();

    std::cout << "\n==========================================\n";
    std::cout << "       Marklar Supermarket Receipt       \n";
    std::cout << "==========================================\n";
    std::cout << "| Item Name        | Price       | Qty           | Free | Total        |\n";
    std::cout << "------------------------------------------------------------------------\n";
    Currency * TotalPrice = nullptr;

    if(ClientCurrency == "USD")
    TotalPrice = new USD(0.0);
    else if(ClientCurrency == "IRR")
    TotalPrice = new IRR(0.0);
    else if(ClientCurrency == "EUR")
    TotalPrice = new EUR(0.0);


    for (const auto &item : cart)
    {
        if (ClientCurrency == "EUR")
            item->SetPrice(new EUR(item->getPrice()->ToEUR()));
        else if (ClientCurrency == "IRR")
            item->SetPrice(new IRR(item->getPrice()->ToIRR()));
        std ::cout << *item;
        *TotalPrice += *item->Totalprice();
    }

    std ::cout << "------------------------------------\n";
    std ::cout << "Total Price = " << TotalPrice->GetAmount() <<'\n';
    client->WithDraw(TotalPrice);

    if (ShopCurrency == "IRR")
        Shop->Deposit(new IRR(TotalPrice->ToIRR()));
    else if (ShopCurrency == "USD")
        Shop->Deposit(new IRR(TotalPrice->ToEUR()));
    else if (ShopCurrency == "EUR")
        Shop->Deposit(new IRR(TotalPrice->ToUSD()));
        std :: cout << "Shop has a total of ="<<Shop->GetBalance()->GetAmount() << " " << Shop->GetBalance()->GetSymbol()<<'\n';
        delete TotalPrice;
    }