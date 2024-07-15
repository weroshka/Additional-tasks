#include<iostream>
#include "functions.hpp"

int main() 
{
    int n;
    
    int mas[2000];
    
    ver::Input(n, mas);

    int i = 0;
    while (i < n)
    {
        if (ver::SumOfDigits(mas[i]) == 15)
        {
            for (int k = n - 1; k >= i; k--)
            {
                mas[k + 1] = mas[k];
             
            }
            n++;
            i++;
        }
        i++;
    }
    
    for (int i = 0; i < n; i++)
    {
        if (ver::IsProst(mas[i]))
        {
            for (int j = i; j <= n - 1; j++)
                mas[j] = mas[j + 1];
            n--;
            i--;
        }
    }

    ver::Output(n, mas);

    return 0;
}
