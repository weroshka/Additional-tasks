#include <iostream>

int main()
{
    int Q1, P1, Q2, P2, A;
    int min_price = INT_MAX;
    int s = INT_MAX;
    std::cin >> Q1 >> P1 >> Q2 >> P2 >> A;
    
    for (int i = 0; i < 1000; i++)
    {
        for (int j = 0; j < 1000; j++)
        {
            if ((i * Q1 + j * Q2) >= A)
            {
                s = i * P1 + j * P2;
            }
            if (s < min_price)
            {
                min_price = s;
            }
        }
    }
    std::cout << min_price;
}