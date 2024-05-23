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

Fixed::Fixed() { setRawBits( 0 ); }

Fixed::Fixed( const int integerNumber )
{
    setRawBits( integerNumber << this->fractionBits );
}

Fixed::Fixed( const float floatNumber )
{
    setRawBits( roundf( floatNumber * (float)( 1 << this->fractionBits ) ) );
}

Fixed::~Fixed() {}

Fixed::Fixed( const Fixed &other ) { *this = other; }

int Fixed::getRawBits( void ) const { return ( this->fixedPoint ); }

void Fixed::setRawBits( int const raw ) { this->fixedPoint = raw; }

float Fixed::toFloat( void ) const
{
    return ( (float)this->fixedPoint / (float)( 1 << this->fractionBits ) );
}

int Fixed::toInt( void ) const
{
    return ( this->fixedPoint >> this->fractionBits );
}

std::ostream &operator<<( std::ostream &stream, const Fixed &fixed )
{
    stream << fixed.toFloat();
    return ( stream );
}

Fixed& Fixed::operator=( const Fixed& other )
{
    if ( this != &other )
    {
        LOG( "Copy assignment operator called" );
        this->fixedPoint = other.getRawBits();
    }
    return *this;
}
bool Fixed::operator<( const Fixed &other )
{
    return this->fixedPoint < other.fixedPoint;
}

bool Fixed::operator>( const Fixed &other )
{
    return this->fixedPoint > other.fixedPoint;
}

bool Fixed::operator<=( const Fixed &other )
{
    return this->fixedPoint <= other.fixedPoint;
}

bool Fixed::operator>=( const Fixed &other )
{
    return this->fixedPoint >= other.fixedPoint;
}

bool Fixed::operator==( const Fixed &other )
{
    return this->fixedPoint == other.fixedPoint;
}

bool Fixed::operator!=( const Fixed &other ) { return !( *this == other ); }

Fixed Fixed::operator++()
{
    this->fixedPoint++;
    return ( *this );
}

Fixed Fixed::operator--()
{
    this->fixedPoint--;
    return ( *this );
}

Fixed Fixed::operator++( int )
{
    Fixed temp = *this;
    ++*this;
    return ( temp );
}

Fixed Fixed::operator--( int )
{
    Fixed temp = *this;
    --*this;
    return ( temp );
}

Fixed Fixed::operator+( const Fixed &other )
{
    return Fixed( toFloat() + other.toFloat() );
}

Fixed Fixed::operator-( const Fixed &other )
{
    return Fixed( toFloat() - other.toFloat() );
}

Fixed Fixed::operator*( const Fixed &other )
{
    return Fixed( toFloat() * other.toFloat() );
}

Fixed Fixed::operator/( const Fixed &other )
{
    return Fixed( toFloat() / other.toFloat() );
}

const Fixed &Fixed::max( const Fixed &ref1, const Fixed &ref2 )
{
    if ( (Fixed)ref1 > (Fixed)ref2 )
        return ( ref1 );
    return ( ref2 );
}

const Fixed &Fixed::min( const Fixed &ref1, const Fixed &ref2 )
{
    if ( (Fixed)ref1 > (Fixed)ref2 )
        return ( ref1 );
    return ( ref2 );
}

Fixed &Fixed::max( Fixed &ref1, Fixed &ref2 )
{
    if ( ref1 > ref2 )
        return ( ref1 );
    return ( ref2 );
}

Fixed &Fixed::min( Fixed &ref1, Fixed &ref2 )
{
    if ( ref1 > ref2 )
        return ( ref1 );
    return ( ref2 );
}