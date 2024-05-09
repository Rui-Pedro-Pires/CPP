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
    int level;
    if (argc != 2)
        return (std::cerr << "Error missing arguments: syntax <./harlFilter <number>>"<< std::endl, 1);
    level = atoi(argv[1]);
    if (std::string(argv[1]).length() != 1 || !isdigit(*argv[1]) || level > 3 || level < 0)
        return (std::cerr << "Invalid level: please introduce a number between 0 and 3" << std::endl, 1);
    switch(level) {
        case 0:
            harl.complain("DEBUG");
        break ;
        case 1:
            harl.complain("DEBUG");
            harl.complain("INFO");
        break ;
        case 2:
            harl.complain("DEBUG");
            harl.complain("INFO");
            harl.complain("WARNING");
            
        break ;
        case 3:
            harl.complain("DEBUG");
            harl.complain("INFO");
            harl.complain("WARNING");
            harl.complain("ERROR");
        break ;
    }
    return (0);
}