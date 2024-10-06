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

#include <bits/stdc++.h>

#include <iostream>

template <typename T>
class Array
{
private:
    T* array;

public:
    Array();
    Array( unsigned int N );
    ~Array();
    Array( const Array& other );
    Array& operator=( const Array& other );
    T& operator[]( int i );
    int size();
};

#include "Array.tpp"

#endif
