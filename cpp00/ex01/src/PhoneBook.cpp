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

PhoneBook::PhoneBook()
{
    this->_i = 0;
    this->_total_contacts = 0;
}

PhoneBook::~PhoneBook()
{
}

void    PhoneBook::render_add_menu(std::string str)
{
    std::cout << " _______________________" << std::endl;
    std::cout << "|                       |" << std::endl;
    std::cout << "|       \033[31mADD MENU\033[0m        |" << std::endl;
    std::cout << "|_______________________|" << std::endl;
    std::cout << "|                       |" << std::endl;
    std::cout << "|";
    std::cout << std::left << std::setw(23) << str;
    std::cout << "|" << std::endl;
    std::cout << "|_______________________|" << std::endl;
    std::cout << std::endl;
}

void    PhoneBook::render_main_menu()
{
    std::cout << " ________________________________" << std::endl;
    std::cout << "|                                |" << std::endl;
    std::cout << "|        \033[31mChoose a command\033[0m        |" << std::endl;
    std::cout << "|________________________________|" << std::endl;
    std::cout << "|          |          |          |" << std::endl;
    std::cout << "|    \033[32mADD\033[0m   |  \033[32mSEARCH\033[0m  |   \033[32mEXIT\033[0m   |" << std::endl;
    std::cout << "|__________|__________|__________|" << std::endl;
    std::cout << std::endl;
}

void    PhoneBook::render_search_menu()
{
    int x = 0;

    std::cout << " __________________________________________" << std::endl;
    std::cout << "|          |          |          |          |" << std::endl;
    std::cout << "|  Index   |Firstname | Lastname | Nickname |" << std::endl;
    std::cout << "|__________|__________|__________|__________|" << std::endl;
    while (x < _total_contacts)
    {
        std::cout << "|          |          |          |          |" << std::endl;
        std::cout << "|" << std::right << std::setw(10) << x + 1 << "|";
        std::cout << std::right << std::setw(10) << trim_string(_contacts_list[x].get_first_name()) << "|";
        std::cout << std::right << std::setw(10) << trim_string(_contacts_list[x].get_last_name()) << "|";
        std::cout << std::right << std::setw(10) << trim_string(_contacts_list[x].get_nick_name()) << "|" << std::endl;
        std::cout << "|__________|__________|__________|__________|" << std::endl;
        x++;
    }
    std::cout << std::endl;
}

void    PhoneBook::add_contact()
{
    std::string str;

    if (_i == 8)
        _i = 0;
    system("clear");
    render_add_menu("First name");
    std::cout << "Input: ";
    while (std::getline(std::cin, str))
    {
        if (!ft_isalpha(str) || str.empty())
        {
            system("clear");
            render_add_menu("First name");
            std::cout << "Invalid input, try again!" << std::endl;
            std::cout << "Input: ";
            continue;
        }
        _contacts_list[_i].set_first_name(str);
        break;
    }
    system("clear");
    render_add_menu("Last name");
    std::cout << "Input: ";
    while (std::getline(std::cin, str))
    {
        if (!ft_isalpha(str) || str.empty())
        {
            system("clear");
            render_add_menu("Last name");
            std::cout << "Invalid input, try again!" << std::endl;
            std::cout << "Input: ";
            continue;
        }
        _contacts_list[_i].set_last_name(str);
        break;
    }
    system("clear");
    render_add_menu("Nickname");
    std::cout << "Input: ";
    while (std::getline(std::cin, str))
    {
        if (!ft_isalpha(str) || str.empty())
        {
            system("clear");
            render_add_menu("Nickname");
            std::cout << "Invalid input, try again!" << std::endl;
            std::cout << "Input: ";
            continue;
        }
        _contacts_list[_i].set_nick_name(str);
        break;
    }
    system("clear");
    render_add_menu("Darkest secret");
    std::cout << "Input: ";
    while (std::getline(std::cin, str))
    {
        if (str.empty())
        {
            system("clear");
            render_add_menu("Darkest secret");
            std::cout << "Invalid input, try again!" << std::endl;
            std::cout << "Input: ";
            continue;
        }
        _contacts_list[_i].set_darkest_secret(str);
        break;
    }
    system("clear");
    render_add_menu("Phonenumber");
    std::cout << "Input: ";
    while (std::getline(std::cin, str))
    {
        if (!ft_isdigit(str) || str.length() != 9)
        {
            system("clear");
            render_add_menu("Phonenumber");
            std::cout << "Invalid input, try again!" << std::endl;
            std::cout << "Input: ";
            continue;
        }
        _contacts_list[_i].set_phone_number(atoi(str.c_str()));
        break;
    }
    if (_total_contacts < 8)
        _total_contacts++;
    _i++;
}

void    PhoneBook::search_contacts()
{
    int num;
    std::string str;

    std::cout << "Introduce the index of the search or ENTER to exit: ";
    while (getline(std::cin, str))
    {
        if (str.empty())
            return ;
        if (ft_isdigit(str) && atoi(str.c_str()) - 1 < _total_contacts && atoi(str.c_str()) - 1 >= 0)
        {
            num = atoi(str.c_str());
            std::cout << "First name: " << _contacts_list[num - 1].get_first_name() << std::endl;
            std::cout << "Last name: " << _contacts_list[num - 1].get_last_name() << std::endl;
            std::cout << "Nickname: " << _contacts_list[num - 1].get_nick_name() << std::endl;
            std::cout << "Darkest secret: " << _contacts_list[num - 1].get_darkest_secret() << std::endl;
            std::cout << "Phonenumber: " << _contacts_list[num - 1].get_phone_number() << std::endl;
            std::cout << std::endl;
            std::cout << "Introduce the index of the search or ENTER to exit: ";
        }
        else
        {
            std::cout << "Invalid index, try again!" << std::endl;
            std::cout << "Introduce the index of the search or ENTER to exit: ";
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

