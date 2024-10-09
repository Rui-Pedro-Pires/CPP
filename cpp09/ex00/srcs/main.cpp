/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiolive  <ruiolive@student.42.fr   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 12:16:43 by ruiolive          #+#    #+#             */
/*   Updated: 2024/10/07 12:16:43 by ruiolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/BitcoinExchange.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
        return (1);
    std::fstream file(argv[1]);
    if (!file.is_open())
    {
        std::cerr << "Error opening file: " << argv[1] << std::endl;
        return (1);
    }

    BitcoinExchange bitcoin;
    std::string line;

    bitcoin.readDataBase();
    bitcoin.getValues();
    std::getline(file, line);
    while (!file.eof())
    {
        std::getline(file, line);
        bitcoin.checkForValue(line);
    }
    file.close();
}
