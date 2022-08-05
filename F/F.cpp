#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> makeV(int pr, int lang)
{
    std::vector<int> v;
    for (int j = 0; j < pr; j++)
    {
        int bitWiseRep = 0;
        for (int i = 0; i < lang; i++)
        {
            int dummy;
            std::cin >> dummy;
            dummy <<= (lang - i - 1);
            bitWiseRep += dummy;
        }
        v.push_back(bitWiseRep);
    }
    return v;
}

int makeMask(int languages)
{
    int mask = 0;
    while ((languages - 1) > -1)
    {
        mask += 1 << (languages - 1);
        languages -= 1;
    }
    return mask;
}


bool chckSubsetValidity(std::vector<int> &v, int mask)
{
    int compInt = v[0];
    for (int i = 1; i < v.size(); i++)
    {
        compInt |= v[i];
    }
    if (compInt == mask)
    {
        return true;
    }
    return false;
}


void mkPowerS(std::vector<int> &initV, int programmers, int languages)
{
    int numberOfLanguageCobinations = 0;
    std::vector<bool> v;
    v.reserve(programmers);
    for (int i = 0; i < programmers; i++)
    {
        v.push_back(0);
    }
    for (int i = 0; i < programmers; i++)
    {
        v[i] = 1;
        do
        {
            std::vector<int> tempV;
            for (int j = 0; j < programmers; j++)
            {
                if (v[j])
                {
                    tempV.push_back(initV[j]);
                }
            }

            int mask = makeMask(languages);
            if (chckSubsetValidity(tempV, mask))
            {
                numberOfLanguageCobinations += 1;
            }

        } while (prev_permutation(v.begin(), v.end()));
    }
    std::cout << numberOfLanguageCobinations;
}


int main()
{
    int programmers, languages;
    std::cin >> programmers >> languages;
    if (languages == 0)
    {
        std::cout << 0;
        return 0;
    }
    std::vector<int> v = makeV(programmers, languages);
    mkPowerS(v, programmers, languages);

    return 0;

}