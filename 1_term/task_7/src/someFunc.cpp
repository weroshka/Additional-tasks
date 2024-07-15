#include <iostream>
#include "functions.hpp"
#include <vector>

namespace ver
{

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


    
}