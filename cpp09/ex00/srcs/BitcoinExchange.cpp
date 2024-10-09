/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiolive  <ruiolive@student.42.fr   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 11:41:05 by ruiolive          #+#    #+#             */
/*   Updated: 2024/10/09 11:41:05 by ruiolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::~BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
    this->_multimap = other._multimap;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
    if (this != &other)
    {
        this->_multimap = other._multimap;
    }
    return *this;
}

void BitcoinExchange::insertValue(std::string str, int i)
{
    this->_multimap.insert(std::pair<std::string, int>(str, i));
}

void BitcoinExchange::getValues()
{
    for (iterator it = this->_multimap.begin(); it != this->_multimap.end(); it++)
        std::cout << it->first << ": " << it->second << std::endl;
}