/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiolive  <ruiolive@student.42.fr   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 12:06:58 by ruiolive          #+#    #+#             */
/*   Updated: 2024/05/21 12:06:58 by ruiolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"

Fixed::Fixed()
{
    this->fixedPoint = 0;
    LOG( "Default constructor called" );
}

Fixed::~Fixed() { LOG( "Destructor called" ); }

Fixed::Fixed( const Fixed& other )
{
    LOG( "Copy constructor called" );
    *this = other;
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

int Fixed::getRawBits( void ) const
{
    LOG( "getRawBits member function called" );
    return ( this->fixedPoint );
}

void Fixed::setRawBits( int const raw )
{
    LOG( "setRawBits member function called" );
    this->fixedPoint = raw;
}
