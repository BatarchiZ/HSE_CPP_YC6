//
// Created by Iskander Sergazin on 19.04.2022.
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
    int n;
    std::cin >> n;
    int largestNumber = n;
    int nCopy = n;
    int counter = 0;
    while (nCopy != 0) //Get number of binary digits
    {
        counter += 1;
        nCopy >>= 1;
    }
    for (int i = 0; i < counter; i++)
    {
        if (getBit(n, 0))
        {
            n >>= 1;
            int dirtyBit = 1;
            dirtyBit <<= (counter - 1);
            n += dirtyBit;
        } else
        {
            n >>= 1;
        }
        if (largestNumber < n)
        {
            largestNumber = n;
        }
    }
    std::cout << largestNumber;
    return 0;
}