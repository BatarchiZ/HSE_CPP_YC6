//
// Created by Iskander Sergazin on 15.04.2022.
//
#include <iostream>

bool getBit(int a, int i)
{
    int k = 1;
    k <<= i;
    return a & k;
}

int main()
{
    int A, i;
    std::cin >> A >> i;
    std::cout << getBit(A,i);
}