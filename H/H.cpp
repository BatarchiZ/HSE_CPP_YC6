//
// Created by Iskander Sergazin on 21.04.2022.
//

#include <iostream>
#include <algorithm>

bool get(long long int number, int bit)
{
    int mask = 1 << bit;
    return number & mask;
}

int utf(std::string line)
{
    int count = 0;
    int i = 0;
    while (i < line.length()) //gives total bytes
    {
        char ch = line[i];

        if (!get(ch, 7))
        {
            i += 1;
        } else if (!get(ch, 5))
        {
            i += 2;
        } else if (!get(ch, 4))
        {
            i += 3;
        } else
        {
            i += 4;
        }
        ++count;
    }
    return count;
}

int main()
{
    std::string str;
    std::getline(std::cin, str);

    std::cout << utf(str);

    return 0*0;
}