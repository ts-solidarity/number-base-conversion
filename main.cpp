#include <algorithm>
#include <iostream>
#include <string>
#include <bits/ranges_algo.h>

int convert(const int& decimal, const int& base)
{

    if (base == 1)
    {
        std::cout << "Base cannot be 1" << std::endl;
        return decimal;
    }

    if (base > 10)
    {
        std::cout << "Base cannot be more than 10" << std::endl;
        return decimal;
    }

    std::string answer;
    int divident = decimal;
    const int divisor = base;
    int quotient = divident / divisor;
    int remainder = divident % divisor;
    answer += std::to_string(remainder);

    if (quotient < divisor)
    {
        answer += std::to_string(quotient);
    }

    while (quotient >= (divisor - 1))
    {
        divident = quotient;
        quotient = divident / divisor;
        remainder = divident % divisor;
        answer += std::to_string(remainder);
    }

    std::ranges::reverse(answer);
    return stoi(answer);

}



int main()
{

    bool go = true;

    while (go)
    {
        int decimal;
        int base;
        std::cout << "Enter decimal number: ";
        std::cin >> decimal;
        std::cout << "Enter base: ";
        std::cin >> base;
        std::cout << convert(decimal, base) << std::endl;
        std::string answer;
        std::cout << "Do you want to continue? (y/n) ";
        std::cin >> answer;
        go = (answer == "y" || answer == "Y");
    }

}


