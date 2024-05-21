/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiolive  <ruiolive@student.42.fr   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 13:50:26 by ruiolive          #+#    #+#             */
/*   Updated: 2024/05/21 13:50:26 by ruiolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"

Fixed::Fixed()
{
    setRawBits(0);
    LOG( "Default constructor called" );
}

Fixed::Fixed( const int integerNumber )
{
    setRawBits(integerNumber << this->fractionBits);
    LOG( "Int constructor called" );
}

Fixed::Fixed( const float floatNumber )
{
    setRawBits(floatNumber * (float)(1 << this->fractionBits));
    LOG( "Float constructor called" );
}

Fixed::~Fixed()
{
    LOG( "Destructor called" );
}

Fixed::Fixed( const Fixed& other )
{
    LOG( "Copy constructor called" );
    *this = other;
}

int Fixed::getRawBits( void ) const
{
    LOG( "getRawBits member function called" );
    return (this->fixedPoint);
}

void Fixed::setRawBits( int const raw )
{
    LOG( "setRawBits member function called" );
    this->fixedPoint = raw;
}

float Fixed::toFloat( void ) const
{
    return ((float)this->fixedPoint / (float)(1 << this->fractionBits));
}

int Fixed::toInt( void ) const
{
    return (this->fixedPoint >> this->fractionBits);
}

std::ostream& operator<<( std::ostream& stream, const Fixed& fixed )
{
    stream << fixed.toFloat();
    return (stream);
}

void Fixed::operator=( const Fixed& other )
{
    LOG( "Copy assignment operator called" );
    setRawBits(other.getRawBits());
}

bool Fixed::operator<(const Fixed& other )
{
    return this->fixedPoint < other.fixedPoint;
}

bool Fixed::operator>(const Fixed& other )
{
    return this->fixedPoint > other.fixedPoint;
}

bool Fixed::operator<=(const Fixed& other )
{
    return this->fixedPoint <= other.fixedPoint;
}

bool Fixed::operator>=(const Fixed& other )
{
    return this->fixedPoint >= other.fixedPoint;
}

bool Fixed::operator==(const Fixed& other )
{
    return this->fixedPoint == other.fixedPoint;
}

bool Fixed::operator!=(const Fixed& other )
{
    return !(*this == other);
}

Fixed Fixed::operator+(const Fixed& other)
{
    return Fixed(this->fixedPoint + other.getRawBits());
}

void Fixed::operator++(int)
{
    this->fixedPoint++;
}

void Fixed::operator--(int)
{
    this->fixedPoint--;
}

Fixed Fixed::operator-(const Fixed& other)
{
    return Fixed(this->fixedPoint - other.getRawBits());
}

Fixed Fixed::operator*(const Fixed& other)
{
    return Fixed(this->fixedPoint * other.getRawBits());
}

Fixed Fixed::operator/(const Fixed& other)
{
    return Fixed(this->fixedPoint / other.getRawBits());
}


// Fixed& Fixed::max(const Fixed& ref1, const Fixed& ref2)
// {
//     if (ref1 > ref2)
//         return (ref1);
//     return (ref2);
// }

// Fixed& Fixed::max(const Fixed& ref1, const Fixed& ref2)
// {
//     if (ref1 > ref2)
//         return (ref1);
//     return (ref2);
// }