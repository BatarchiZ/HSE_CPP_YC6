#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

std::vector<std::string> getElements(int n)
{
    std::vector<std::string> v;
    for (int i = 0; i < n; i++)
    {
        std::string dummy;
        std::cin >> dummy;
        v.push_back(dummy);
    }
    return v;
}

void printV(std::vector<std::string> &vS)
{
    std::cout << "[";
    for (int i = 0; i < vS.size() - 1; i++)
    {
        std::cout << vS[i] << ",";
    }
    std::cout << vS[vS.size() - 1] << "]" << std::endl;
}

void makeOrderedPowerS(std::vector<std::string> &initV, int n)
{
    std::vector<bool> v;
    v.reserve(n);
    for (int i = 0; i < n; i++)
    {
        v.push_back(0);
    }
    for (int i = 0; i < n; i++)
    {
        v[i] = 1;
        do
        {
            std::vector<std::string> tempV;
            for (int j = 0; j < n; j++)
            {
                if (v[j])
                {
                    tempV.push_back(initV[j]);
                }
            }
            printV(tempV);

        } while (prev_permutation(v.begin(), v.end()));
    }
}


int main()
{
    int n;
    std::cin >> n;
    std::cout << "[]" << std::endl;

    std::vector<std::string> vOfElements = getElements(n);
    makeOrderedPowerS(vOfElements, n);
    return 0;
}



