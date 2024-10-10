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

BitcoinExchange::BitcoinExchange( const BitcoinExchange &other )
{
    this->_database = other._database;
}

BitcoinExchange &BitcoinExchange::operator=( const BitcoinExchange &other )
{
    if ( this != &other )
    {
        this->_database = other._database;
    }
    return *this;
}

void BitcoinExchange::readDataBase( void )
{
    std::fstream file( "data.csv" );
    std::string line;
    std::string word;
    std::vector<std::string> words;

    if ( !file.is_open() )
        throw std::exception();
    std::getline( file, line );
    while ( !file.eof() )
    {
        std::getline( file, line );
        std::stringstream ss( line );
        words.clear();
        while ( !ss.eof() )
        {
            std::getline( ss, word, ',' );
            words.push_back( word );
        }
        int date = this->castDate( words[0] );
        this->_database[date] = strtof( words[1].c_str(), NULL );
    }
    file.close();
}

void BitcoinExchange::checkForValue( std::string &line )
{
    struct tm tm;
    std::stringstream ss( line );
    std::string word;
    std::vector<std::string> words;

    while ( !ss.eof() )
    {
        std::getline( ss, word, '|' );
        word.erase( remove( word.begin(), word.end(), ' ' ), word.end() );
        words.push_back( word );
    }
    if ( strptime( words[0].c_str(), "%Y-%m-%d", &tm ) )
        std::cerr << words[0] << " => ";
    else
    {
        std::cerr << "Error: bad input => " << words[0] << std::endl;
        return;
    }
    float number = strtof( words[1].c_str(), NULL );
    if ( number >= 0 && number <= 1000 )
    {
        std::cout << number << " = ";
    }
    else if ( number < 0 )
    {
        std::cerr << "Error: not a positive number." << words[0] << std::endl;
        return;
    }
    else
    {
        std::cerr << "Error: too large a number." << words[0] << std::endl;
        return;
    }
    std::map<int, float>::iterator it;

    int date = this->castDate( words[0] );

    while ( date )
    {
        it = _database.find( date );
        if ( it != _database.end() )
        {
            std::cout << it->second * number << std::endl;
            return;
        }
        date--;
    }
    std::cerr << "date not found" << std::endl;
}

int BitcoinExchange::castDate( std::string &date )
{
    struct tm tm;

    strptime( date.c_str(), "%Y-%m-%d", &tm );
    return ( 10000 * tm.tm_year + 100 * tm.tm_mon + tm.tm_mday );
}

void BitcoinExchange::getValues()
{
    for ( iterator it = this->_database.begin(); it != this->_database.end(); it++ )
        std::cout << it->first << ": " << it->second << std::endl;
}