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
    this->fixedPoint = 0;
    LOG( "Default constructor called" );
}

Fixed::Fixed( const int integerNumber )
{
    this->fixedPoint = integerNumber * (int)(1 << this->fractionBits);
    LOG( "Default constructor called" );
}

Fixed::Fixed( const float floatNumber )
{
    this->fixedPoint = this->fixedPoint = floatNumber * (float)(1 << this->fractionBits);
    LOG( "Default constructor called" );
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

void Fixed::operator=( const Fixed& other )
{
    LOG( "Copy assignment operator called" );
    this->fixedPoint = other.getRawBits();
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
    return (this->fixedPoint * (float)(1 << this->fractionBits));
}

std::ostream& operator<<( std::ostream& stream, const Fixed& fixed )
{
    stream << fixed.toFloat();
    return (stream);
}