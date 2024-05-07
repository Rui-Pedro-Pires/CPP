#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <iomanip>
#include "../includes/PhoneBook.hpp"
#include "../includes/Contact.hpp"

bool    ft_isdigit(std::string str)
{
    std::string:: iterator itr;
    for (itr = str.begin(); itr < str.end(); itr++) {
        if (!isdigit(*itr))
            return (false);
    }
    return (true);
}

bool    ft_isalpha(std::string str)
{
    std::string:: iterator itr;
    for (itr = str.begin(); itr < str.end(); itr++) {
        if (!isalpha(*itr))
            return (false);
    }
    return (true);
}

void    PhoneBook::add_contact()
{
    std::string str;

    if (i == 8)
        i = 0;
    system("clear");
    std::cout << "First Name: ";
    while (std::getline(std::cin, str))
    {
        if (!ft_isalpha(str) || str.empty())
        {
            system("clear");
            std::cout << "Invalid input, try again!" << std::endl;
            std::cout << "First Name: ";
            continue;
        }
        contacts_list[i].set_first_name(str);
        break;
    }
    system("clear");
    std::cout << "Last Name: ";
    while (std::getline(std::cin, str))
    {
        if (!ft_isalpha(str) || str.empty())
        {
            system("clear");
            std::cout << "Invalid input, try again!" << std::endl;
            std::cout << "Last Name: ";
            continue;
        }
        contacts_list[i].set_last_name(str);
        break;
    }
    system("clear");
    std::cout << "Nickname: ";
    while (std::getline(std::cin, str))
    {
        if (!ft_isalpha(str) || str.empty())
        {
            system("clear");
            std::cout << "Invalid input, try again!" << std::endl;
            std::cout << "Nickname: ";
            continue;
        }
        contacts_list[i].set_nick_name(str);
        break;
    }
    system("clear");
    std::cout << "Darkest secret: ";
    while (std::getline(std::cin, str))
    {
        if (str.empty())
        {
            system("clear");
            std::cout << "Invalid input, try again!" << std::endl;
            std::cout << "Darkest secret: ";
            continue;
        }
        contacts_list[i].set_darkest_secret(str);
        break;
    }
    system("clear");
    std::cout << "Phonenumber: ";
    while (std::getline(std::cin, str))
    {
        if (!ft_isdigit(str) || str.length() != 9)
        {
            system("clear");
            std::cout << "Invalid input, try again!" << std::endl;
            std::cout << "Phonenumber: ";
            continue;
        }
        contacts_list[i].set_phone_number(atoi(str.c_str()));
        break;
    }
    if (total_contacts < 8)
        total_contacts++;
    i++;
}

void    PhoneBook::search_contacts()
{
    int x;
    int num;
    std::string str;

    while (true)
    {
        std::cout << " __________________________________________" << std::endl;
        std::cout << "|          |          |          |          |" << std::endl;
        std::cout << "|  Index   |Firstname | Lastname | Nickname |" << std::endl;
        std::cout << "|__________|__________|__________|__________|" << std::endl;
        x = 0;
        while (x < total_contacts)
        {
            std::cout << "|          |          |          |          |" << std::endl;
            std::cout << "|" << std::right << std::setw(10) << x + 1 << "|";
            std::cout << std::right << std::setw(10) << trim_string(contacts_list[x].get_first_name()) << "|";
            std::cout << std::right << std::setw(10) << trim_string(contacts_list[x].get_last_name()) << "|";
            std::cout << std::right << std::setw(10) << trim_string(contacts_list[x].get_nick_name()) << "|" << std::endl;
            std::cout << "|__________|__________|__________|__________|" << std::endl << std::endl;
            x++;
        }
        std::cout << "Introduce the index of the search or ENTER to exit: ";
        while (getline(std::cin, str))
        {
            if (str.empty())
                return ;
            if (ft_isdigit(str) && atoi(str.c_str()) - 1 < total_contacts && atoi(str.c_str()) - 1 >= 0)
            {
                num = atoi(str.c_str());
                std::cout << "First name: " << contacts_list[num - 1].get_first_name() << std::endl;
                std::cout << "Last name: " << contacts_list[num - 1].get_last_name() << std::endl;
                std::cout << "Nickname: " << contacts_list[num - 1].get_nick_name() << std::endl;
                std::cout << "Darkest secret: " << contacts_list[num - 1].get_darkest_secret() << std::endl;
                std::cout << "Phonenumber: " << contacts_list[num - 1].get_phone_number() << std::endl;
                break;
            }
            else
            {
                std::cout << "Invalid index, try again!" << std::endl;
                std::cout << "Introduce the index of the search or ENTER to exit: ";
            }
        }
    }
}

std::string PhoneBook::trim_string(std::string str)
{
    int lenght = str.length();
    if (lenght > 10)
    {
        std::string trimmed = str.substr(0, 9) + ".";
        return (trimmed);
    }
    return (str);
}

