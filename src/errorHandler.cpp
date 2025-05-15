#include <../include/errorHandler.hpp>
#include <string>
#include <cctype>
#include <stdexcept>
bool CheckString(std ::string test)
{
    if (test.empty())
    {
        throw std ::invalid_argument("Error : empty string is invalid input !!\n");
    }
    if (test.empty())
    {
        throw std ::invalid_argument("Error : empty string is invalid input !!\n");
    }
    for (auto c : test)
    {
        if (isdigit(c))
        {
            throw std ::invalid_argument("Error : Number isn't availiable!!\n");
        }
    }
    return true;
}
bool CheckFloat(std ::string test)
{
    if (test.empty())
    {
        throw std ::invalid_argument("Error : empty string is invalid input !!\n");
    }
    try
    {
        stod(test);
    }
    catch (std ::invalid_argument &e)
    {
        std ::cerr << e.what(); //"Invalid floating point!"
    }
    catch (std ::out_of_range &e)
    {
        std ::cerr << e.what();
    }
    if (stod(test) < 0)
    {
        throw std ::invalid_argument("negative input is unavailiable!!\n");
    }
    return true;
}
bool CheckInt(std ::string test)
{
    if (test.empty())
    {
        throw std ::invalid_argument("Error : empty string is invalid input !!\n");
    }
    try
    {
        stoi(test);
    }
    catch (std ::invalid_argument &e)
    {
        std ::cerr << e.what(); //"Invalid int!"
    }
    catch (std ::out_of_range &e)
    {
        std ::cerr << e.what();
    }
    if (stoi(test) < 0)
    {
        throw std ::invalid_argument("negative input is unavailiable!!\n");
    }
    return true;
}
