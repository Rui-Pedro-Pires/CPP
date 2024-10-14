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
    BitcoinExchange bitcoin;
    std::string line;

    if (argc != 2)
    {
        std::cerr << "Error: could not open file" << std::endl;
        return (1);
    }
    std::fstream file(argv[1]);
    if (!file.is_open())
    {
        std::cerr << "Error: could not open file" << std::endl;
        return (1);
    }

    try
    {
        bitcoin.readDataBase();
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    std::getline(file, line);
    while (!file.eof())
    {
        std::getline(file, line);
        if (line.empty())
            continue;
        try
        {
            bitcoin.checkForValue(line);
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }
    }
    file.close();
}
