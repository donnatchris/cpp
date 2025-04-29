#include <iostream>

int main(int ac, char **av)
{
    if (ac < 2)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return (0);
    }
    int i(1);
    while (av[i])
    {
        int j(0);
        while (av[i][j])
            std::cout << (char)std::toupper(av[i][j++]);
        i++;
    }
    std::cout << std::endl;
    return (0);
}
