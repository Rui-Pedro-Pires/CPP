#include <iostream>
#include <stdlib.h>
#include <string.h>

#include "PhoneBook.hpp"

bool    ft_isdigit(std::string str)
{
    std::string:: iterator itr;
    for (itr = str.begin(); itr < str.end(); itr++) {
        if (!isdigit(*itr))
            return (false);
    }
    return (true);
}

bool    ft_isaplhanum(std::string str)
{
    std::string:: iterator itr;
    for (itr = str.begin(); itr < str.end(); itr++) {
        if (!isalnum(*itr))
            return (false);
    }
    return (true);
}

void    PhoneBook::print_error()
{
    std::cout << "Invalid input, try again" << std::endl;
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
        system("clear");
        if (ft_isaplhanum(str))
        {
            contacts_list[i].set_first_name(str);
            break;
        }
        else
            print_error();
    }
    std::cout << "Last Name: ";
    while (std::getline(std::cin, str))
    {
        system("clear");
        if (ft_isaplhanum(str))
        {
            contacts_list[i].set_last_name(str);
            break;
        }
        else
        {
            print_error();
        }
    }
    std::cout << "Nickname: ";
    while (std::getline(std::cin, str))
    {
        system("clear");
        if (ft_isaplhanum(str))
        {
            contacts_list[i].set_nick_name(str);
            break;
        }
        else
            print_error();
    }
    std::cout << "Darkest secret: ";
    while (std::getline(std::cin, str))
    {
        system("clear");
        if (ft_isaplhanum(str))
        {
            contacts_list[i].set_darkest_secret(str);
            break;
        }
        else
            print_error();
    }
    std::cout << "Phonenumber: ";
    while (std::getline(std::cin, str))
    {
        system("clear");
        if (ft_isdigit(str) && str.length() == 9)
        {
            contacts_list[i].set_phone_number(atoi(str.c_str()));
            break;
        }
        else
            print_error();
    }
    if (contacts_total < 8)
        contacts_total++;
    i++;
}

void    PhoneBook::search_contacts()
{
    int x = 0;
    int num;
    std::string str;

    std::cout << " ________________________________________" << std::endl;
    std::cout << "|       |          |          |          |" << std::endl;
    std::cout << "| Index |Firstname | Lastname | Nickname |" << std::endl;
    std::cout << "|_______|__________|__________|__________|" << std::endl;
    while (x < contacts_total)
    {
        std::cout << "|       |          |          |          |" << std::endl;
        std::cout << "|   " << x << "   |";
        std::cout << trim_string(contacts_list[x].get_first_name()) << "|";
        std::cout << trim_string(contacts_list[x].get_last_name()) << "|";
        std::cout << trim_string(contacts_list[x].get_nick_name()) << "|" << std::endl;
        std::cout << "|_______|__________|__________|__________|" << std::endl;
        x++;
    }
    std::cout << "Introduce the index of the search: ";
    while (getline(std::cin, str))
    {
        if (ft_isdigit(str) && atoi(str.c_str()) < contacts_total)
        {
            num = atoi(str.c_str());
            std::cout << "First name: " << contacts_list[num].get_first_name() << std::endl;
            std::cout << "Last name: " << contacts_list[num].get_last_name() << std::endl;
            std::cout << "Nickname: " << contacts_list[num].get_nick_name() << std::endl;
            std::cout << "Darkest secret: " << contacts_list[num].get_darkest_secret() << std::endl;
            std::cout << "Phonenumber: " << contacts_list[num].get_phone_number() << std::endl;
            break;
        }
        else
            std::cout << "Invalid index, try again: ";
    }
}

std::string PhoneBook::trim_string(std::string name)
{
    std::string str = "          ";
    int lenght = name.length();
    if (lenght > 10)
    {
        str.replace(0, 9, name, 0, 9);
        str.replace(9, 1, ".");
        return (str);
    }
    if (lenght < 10)
    {
        str.replace((10 - lenght), lenght, name);
        return (str);
    }
    return (name);
}

