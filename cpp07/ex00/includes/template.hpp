/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   template.hpp                                       :+:      :+:    :+:   */
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
void swap( T& value1, T& value2 )
{
    T temp;

    temp = value1;
    value1 = value2;
    value2 = temp;
}

template <typename T>
T min( T& value1, T& value2 )
{
    if ( value2 < value1 )
        return value2;
    else if ( value1 < value2 )
        return value1;
    else
        return value2;
}

template <typename T>
T max( T& value1, T& value2 )
{
    if ( value2 > value1 )
        return value2;
    else if ( value1 > value2 )
        return value1;
    else
        return value2;
}

#endif