/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiolive  <ruiolive@student.42.fr   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 10:27:00 by ruiolive          #+#    #+#             */
/*   Updated: 2024/05/08 10:27:00 by ruiolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stdlib.h>
#include "../includes/PhoneBook.hpp"

int main()
{
    std::string     str;
    PhoneBook   phonebook;

    system("clear");
    phonebook.render_main_menu();
    std::cout << "Please introduce a command: ";
    while (std::getline(std::cin, str))
    {
        if (str == "ADD")
            phonebook.add_contact();
        else if (str == "SEARCH")
        {
            system("clear");
            phonebook.render_search_menu();
            phonebook.search_contacts();
        }
        else if (str == "EXIT")
            break;
        else if (!str.empty())
        {
            system("clear");
            phonebook.render_main_menu();
            std::cout << "Invalid input, try again!" << std::endl;
            std::cout << "Please introduce a command: ";
            continue;
        }
        system("clear");
        phonebook.render_main_menu();
        std::cout << "Please introduce a command: ";
    }
    system("clear");
    std::cout << "\033[34mGoodbye!\033[0m" << std::endl;
    system("sleep 1");
    system("clear");
}
