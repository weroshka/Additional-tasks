#include <iostream>
#include "functions.hpp"

namespace ver
{
    void Input(int& n, int sequence[1000])
    {
        std::cin >> n;
        for (int i = 0; i < n; i++)
            std::cin >> sequence[i];
    }

    int Maximum(int n, int sequence[1000])
    {
        int maximum = sequence[0];
        for (int i = 0; i < n; i++)
            if (sequence[i] > maximum)
            {
                maximum = sequence[i];
            }

        return maximum;
    }

    int Minimum(int n, int sequence[1000])
    {
        int minimum = INT_MAX;
        for (int i = 0; i < n; i++)
            if (sequence[i] < minimum)
            {
                minimum = sequence[i];
            }

        return minimum;
    }

    void Sort(int n, int sequence[1000])
    {
        for (int i = 0; i < n - 1; i++)
            for (int j = i + 1; j < n; j++)
                if (sequence[i] > sequence[j])
                    std::swap(sequence[i], sequence[j]);
    }

    void Output(int n, int sequence[1000])
    {
        for (int i = 0; i < n; i++)
            std::cout << sequence[i] << " ";
        std::cout << "\n";

        std::cout << "Maximum is " << Maximum(n, sequence) << std::endl;
        std::cout << "Minimum is " << Minimum(n, sequence) << std::endl;
    }
}