#include <iostream>
#include "functions.hpp"

namespace ver
{
    void Input(int& n, int mas[2000])
    {
        std::cout << "n = ";
        std::cin >> n;
        std::cout << "Input ";
        for (int i = 0; i < n; i++)
            std::cin >> mas[i];
    }

    bool IsProst(int x)
    {
        for (int i = 2; i <= sqrt(x); i++)
            if (x % i == 0)
                return false;

        return true;
    }

    int SumOfDigits(int x)
    {
        int sum = 0;
        while (x > 0)
        {
            sum += x % 10;
            x /= 10;
        }
        return sum;
    }

    void Output(int n, int mas[2000])
    {
        std::cout << "Output ";
        for (int i = 0; i < n; i++)
           std::cout << mas[i] << " ";
    }
}