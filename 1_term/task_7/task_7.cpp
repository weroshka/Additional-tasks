#include<iostream>
#include "functions.hpp"
#include <vector>



int main()
{
    std::vector<int> vec;
   
    vec = { 1, 2, 78 };
    for (auto& v : vec)
        std::cout << v << " ";
    std::cout << " \n";
    
   

    for (int i = 0; i < vec.size(); i++)
    {
        if (ver::SumOfDigits(vec[i]) == 15)
        {
            vec.insert(vec.begin() + 1, vec[i]);
            i++;
        }
    }
    

    for (int i = 0; i < vec.size(); i++)
    {
        if (ver::IsProst(vec[i]))
        {
            vec.erase(vec.begin() + i);
            i--;
        }
    }
    

    for (int i = 0; i < vec.size(); i++)
        std::cout << vec[i] << " ";

    return 0;
}
