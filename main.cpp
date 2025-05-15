// #include "include/Bank.hpp"
// #include "include/Currency.hpp"
// #include "include/USD.hpp"
// #include "include/EUR.hpp"
// #include "include/IRR.hpp"
#include "../include/Item.hpp"
#include "../include/Fruit.hpp"
#include "../include/Seasoning.hpp"
#include "../include/Snack.hpp"
using namespace std;
int main()
{
    Fruit apple("Apple" , 2 , 10);
    Snack chips("Chips" , 1.5 , 20);
    Seasoning salt("Salt" , 0.01 , 500);

    ++apple;  ++apple;  ++apple;  ++apple;  ++apple;  ++apple;
    ++chips; ++chips;
    ++salt; ++salt ; ++salt;
    std::cout << "================= Shopping Receipt =================\n"
          << "Item        |Unit Price|Qty & Unit| Free | Total\n"
          << "----------------------------------------------------\n";

    apple.printReceipt(cout);
    chips.printReceipt(cout);
    salt.printReceipt(cout);
    std::cout << "====================================================\n";





    return 0;
}