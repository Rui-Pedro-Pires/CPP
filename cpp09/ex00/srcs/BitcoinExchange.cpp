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
    std::ifstream file("data.csv");
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

void BitcoinExchange::checkForValue(std::string &line)
{
    struct tm tm;
    float number;
    std::stringstream ss(line);
    std::string word;
    std::vector<std::string> words;
    std::map<std::string, float>::iterator it;

    while (!ss.eof())
    {
        std::getline(ss, word, ' ');
        if (word != "|")
            words.push_back(word);
    }
    if (!strptime(words[0].c_str(), "%Y-%m-%d", &tm))
        throw BadDateException();
    number = strtof(words[1].c_str(), NULL);
    if (number < 0)
        throw NegativeNumberException();
    else if (number > 1000)
        throw NumberToLargeException();
    it = this->_database.find(words[0]);
    if (it == this->_database.end())
    {
        it = this->_database.lower_bound(words[0]);
        it--;
        if (it == this->_database.begin())
            throw NoDateToTrackException();
    }
    std::cerr << words[0] << " => ";
    std::cout << number << " = ";
    std::cout << it->second * number << std::endl;
}

const char *BitcoinExchange::BadDateException::what() const throw()
{
    return "Error: bad input => ";
}

const char *BitcoinExchange::NegativeNumberException::what() const throw()
{
    return "Error: not a positive number.";
}

const char *BitcoinExchange::NumberToLargeException::what() const throw()
{
    return "Error: too large a number.";
}

const char *BitcoinExchange::NoDateToTrackException::what() const throw()
{
    return "Error: no date to check => ";
}