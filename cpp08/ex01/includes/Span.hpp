/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiolive  <ruiolive@student.42.fr   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 19:38:39 by ruiolive          #+#    #+#             */
/*   Updated: 2024/10/07 21:21:29 by ruiolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiolive  <ruiolive@student.42.fr   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 19:38:39 by ruiolive          #+#    #+#             */
/*   Updated: 2024/10/07 19:39:17 by ruiolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef SPAN_HPP
#define SPAN_HPP

#include <bits/stdc++.h>

#include <algorithm>
#include <iostream>

class Span
{
private:
    std::vector<int> vec;
    unsigned int maxSize;

public:
    Span();
    Span( unsigned int N );
    ~Span();
    Span( const Span& other );
    Span& operator=( const Span& other );

    void addNumber( int toAdd );
    void addManyNumbers( int* toAdd, int N );
    int shortestSpan();
    int longestSpan();

    class SizeOverflowException : public std::exception
    {
        const char* what() const throw();
    };

    class NoElementsEnoughtException : public std::exception
    {
        const char* what() const throw();
    };
};

#endif
