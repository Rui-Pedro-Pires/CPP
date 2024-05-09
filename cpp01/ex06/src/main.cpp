/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiolive  <ruiolive@student.42.fr   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 16:44:53 by ruiolive          #+#    #+#             */
/*   Updated: 2024/05/08 16:44:53 by ruiolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Harl.hpp"

int main(int argc, char **argv)
{
    Harl harl;
    std::string str;
    if (argc != 2)
        return (std::cerr << "Error missing arguments: syntax <./harlFilter <number>>"<< std::endl, 1);
    str = argv[1];
    if (str != "DEBUG" && str != "WARNING" && str != "ERROR" && str != "INFO")
    {
        LOG("[ Probably complaining about insignificant problems ]");
        return (0);
    }
    switch(argv[1][0]) {
        case 'E':
            harl.complain("ERROR");
            std::cout << std::endl;
        break ;
        case 'W':
            harl.complain("WARNING");
            std::cout << std::endl;
            harl.complain("ERROR");
            std::cout << std::endl;
        break ;
        case 'I':
            harl.complain("INFO");
            std::cout << std::endl;
            harl.complain("WARNING");
            std::cout << std::endl;
            harl.complain("ERROR");
            std::cout << std::endl;
        break ;
        case 'D':
            harl.complain("DEBUG");
            std::cout << std::endl;
            harl.complain("INFO");
            std::cout << std::endl;
            harl.complain("WARNING");
            std::cout << std::endl;
            harl.complain("ERROR");
            std::cout << std::endl;
        break ;
    }
    return (0);
}