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
    std::map<std::string, float> _database;

public:
    BitcoinExchange();
    ~BitcoinExchange();
    BitcoinExchange(const BitcoinExchange &other);
    BitcoinExchange &operator=(const BitcoinExchange &other);

    typedef std::map<std::string, float>::iterator iterator;

    void readDataBase(void);
    void checkForValue(std::string &line);
    class BadDateException : public std::exception
    {
    private:
        std::string _date;

    public:
        BadDateException(std::string date);
        virtual ~BadDateException() throw();
        const char *what() const throw();
    };

    class NumberToLargeException : public std::exception
    {
        const char *what() const throw();
    };

    class NegativeNumberException : public std::exception
    {
        const char *what() const throw();
    };

    class NoDateToTrackException : public std::exception
    {
    private:
        std::string _date;

    public:
        NoDateToTrackException(std::string date);
        virtual ~NoDateToTrackException() throw();
        const char *what() const throw();
    };
};

#endif