#include <iostream>

void    ft_toupper(std::string &str)
{
    int size = str.length();
    for (int i = 0; i < size; i++) {
        str[i] = std::toupper(str[i]);
    }
}

int main(int argc, char **argv)
{
    std::string temp;

    if (argc == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    for (int i = 1; i < argc; i++) {
        temp = (std::string)argv[i];
        ft_toupper(temp);
        std::cout << temp;
    }
    std::cout << std::endl;
}