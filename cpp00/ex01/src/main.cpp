#include <iostream>
#include <stdlib.h>
#include "PhoneBook.hpp"

int main()
{
    std::string     str;
    PhoneBook   phonebook;

    phonebook.i = 0;
    phonebook.contacts_total = 0;
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
        else
            phonebook.print_error();
        system("clear");
        std::cout << "Please introduce a command: ";
    }
    std::cout << std::endl;
}
