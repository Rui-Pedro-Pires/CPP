#include <iostream>
#include <stdlib.h>
#include "../includes/PhoneBook.hpp"

int main()
{
    std::string     str;
    PhoneBook   phonebook;

    system("clear");
    std::cout << "Please introduce a command: ";
    while (std::getline(std::cin, str))
    {
        if (str == "ADD")
            phonebook.add_contact();
        else if (str == "SEARCH")
            phonebook.search_contacts();
        else if (str == "EXIT")
            break;
        else if (!str.empty())
        {
            system("clear");
            std::cout << "Invalid input, try again!" << std::endl;
            std::cout << "Please introduce a command: ";
            continue;
        }
        system("clear");
        std::cout << "Please introduce a command: ";
    }
    system("clear");
}
