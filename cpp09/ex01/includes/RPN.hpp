/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiolive  <ruiolive@student.42.fr   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 11:39:22 by ruiolive          #+#    #+#             */
/*   Updated: 2024/10/09 11:39:22 by ruiolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef RPN_HPP
#define RPN_HPP

#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>

class RPN
{
private:
    std::stack<int> stack;

public:
    RPN();
    ~RPN();
    RPN(const RPN &other);
    RPN &operator=(const RPN &other);

    bool ft_isdigit(std::string &str);
    void doRPN(std::string input);
    class BadCharactersException : public std::exception
    {
        const char *what() const throw();
    };

    class BadOrderException : public std::exception
    {
        const char *what() const throw();
    };

    class BadNumberException : public std::exception
    {
        const char *what() const throw();
    };
};

#endif
