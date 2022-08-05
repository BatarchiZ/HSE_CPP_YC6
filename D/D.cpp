//
// Created by Iskander Sergazin on 15.04.2022.
//
#include <iostream>

bool getBit(unsigned long long int a, int i)
{
    int k = 1;
    k <<= i;
    return a & k;
}

int main()
{
    unsigned long long int x;
    std::cin >> x;
    int counter = 0;
    while(x!= 0)
    {
        if(getBit(x,0))
        {
            counter += 1;
        }
        x >>= 1;
    }
    std::cout << counter;
}

