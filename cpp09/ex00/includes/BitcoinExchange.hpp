/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiolive  <ruiolive@student.42.fr   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 11:39:22 by ruiolive          #+#    #+#             */
/*   Updated: 2024/10/09 11:40:36 by ruiolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <bits/stdc++.h>

#include <ctime>
#include <fstream>
#include <iostream>

class BitcoinExchange
{
private:
    std::map<int, float> _database;

public:
    BitcoinExchange();
    ~BitcoinExchange();
    BitcoinExchange( const BitcoinExchange &other );
    BitcoinExchange &operator=( const BitcoinExchange &other );

    typedef std::map<int, float>::iterator iterator;

    void readDataBase( void );
    void checkForValue( std::string &line );
    int castDate( std::string &date );
    void getValues( void );
};

#endif