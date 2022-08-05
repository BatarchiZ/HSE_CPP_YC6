//
// Created by Iskander Sergazin on 15.04.2022.
//
#include <iostream>


int getBit(int a, int i)
{
    int k = 1;
    k <<= i;
    return a & k;
}

int main()
{
    int i, A;
    int res = 0;
    std::cin >> A >> i;
    while (i != 0)
    {
        int temp = getBit(A, (i - 1));
        res += temp;
        i -= 1;
    }
    std::cout << res;
}