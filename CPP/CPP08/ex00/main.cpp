#include "easyfind.hpp"
#include <vector>

int main()
{
    std::vector<int> a;

    a.push_back(10);
    a.push_back(25);
    a.push_back(12);
    a.push_back(16);
    a.push_back(34);
    a.push_back(12);
    a.push_back(1);

    try
    {
        std::cout << *easyfind(a, 16) << std::endl;
        std::cout << *easyfind(a, 26) << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
}
