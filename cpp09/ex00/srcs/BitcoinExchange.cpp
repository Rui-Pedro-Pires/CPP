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
    this->_database = other._database;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
    if (this != &other)
    {
        this->_database = other._database;
    }
    return *this;
}

void BitcoinExchange::readDataBase(void)
{
    std::fstream file("data.csv");
    std::string line;
    std::string word;
    std::vector<std::string> words;

    if (!file.is_open())
        throw std::exception();
    std::getline(file, line);
    while (!file.eof())
    {
        std::getline(file, line);
        std::stringstream ss(line);
        words.clear();
        while (!ss.eof())
        {
            std::getline(ss, word, ',');
            words.push_back(word);
        }
        this->_database[words[0]] = strtof(words[1].c_str(), NULL);
    }
    file.close();
}

void BitcoinExchange::getValues()
{
    for (iterator it = this->_database.begin(); it != this->_database.end(); it++)
        std::cout << it->first << ": " << it->second << std::endl;
}