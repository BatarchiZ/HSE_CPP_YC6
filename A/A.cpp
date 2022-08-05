#include <iostream>

int main()
{
    int bit, pos;
    std::cin >> bit >> pos;
    int num = 1;
    num = num << pos;
    bit = bit ^ num;
    std::cout << bit;
}

