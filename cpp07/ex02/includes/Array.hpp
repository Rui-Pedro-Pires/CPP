/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiolive  <ruiolive@student.42.fr   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 18:14:05 by ruiolive          #+#    #+#             */
/*   Updated: 2024/10/07 11:14:53 by ruiolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiolive  <ruiolive@student.42.fr   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 16:11:48 by ruiolive          #+#    #+#             */
/*   Updated: 2024/10/04 16:11:48 by ruiolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef TEMPLATE_HPP
#define TEMPLATE_HPP

#include <iostream>

template <typename T>
class Array
{
public:
    Array();
    Array( unsigned int N );
    ~Array();
    Array( const Array& other );
    Array& operator=( const Array& other );
    T& operator[]( int i );
    const T& operator[]( int i ) const;
    int size() const;

private:
    T* array;
    int _size;

    class OverflowIndexException : public std::exception
    {
    public:
        const char* what() const throw();
    };
};

#include "../srcs/Array.tpp"

#endif
