/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiolive  <ruiolive@student.42.fr   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 13:50:22 by ruiolive          #+#    #+#             */
/*   Updated: 2024/05/21 13:50:22 by ruiolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __FIXED_H__
#define __FIXED_H__

#include <iostream>
#include <cmath>
#define LOG( x ) std::cout << x << std::endl;

class Fixed {
private:
    int fixedPoint;
    static const int fractionBits = 8;
public:
    Fixed();
    Fixed( const int integerNumber );
    Fixed( const float floatNumber );
    Fixed( const Fixed& other );
    ~Fixed();
    int getRawBits( void ) const;
    void setRawBits( int const raw );
    float toFloat( void ) const;
    int toInt( void ) const;
    static Fixed& min( Fixed& ref1,  Fixed& ref2 );
    static Fixed& max( Fixed& ref1,  Fixed& ref2);
    // static Fixed& min(const Fixed& ref1, const Fixed& ref2 );
    // static Fixed& max( const Fixed& ref1, const Fixed& ref2 );
    void operator=( const Fixed& other );
    bool operator>( const Fixed& other );
    bool operator>=( const Fixed& other );
    bool operator<=( const Fixed& other );
    bool operator<( const Fixed& other );
    bool operator==( const Fixed& other );
    bool operator!=( const Fixed& other );
    Fixed operator+(const Fixed& other);
    Fixed operator-(const Fixed& other);
    void operator++();
    void operator++(int);
    void operator--();
    void operator--(int);
    Fixed operator*(const Fixed& other);
    Fixed operator/(const Fixed& other);
    friend std::ostream& operator<<( std::ostream& stream, const Fixed& fixed );
};

std::ostream& operator<<( std::ostream& stream, const Fixed& fixed );
Fixed& Fixed::min( Fixed& ref1, Fixed& ref2)
{
    if (ref1 < ref2)
        return (ref1);
    return (ref2);
}

Fixed& Fixed::min(Fixed& ref1,  Fixed& ref2)
{
    if (ref1 < ref2)
        return (ref1);
    return (ref2);
}

#endif