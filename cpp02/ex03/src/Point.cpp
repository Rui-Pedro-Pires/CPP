/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiolive  <ruiolive@student.42.fr   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 14:21:04 by ruiolive          #+#    #+#             */
/*   Updated: 2024/05/22 14:21:04 by ruiolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Point.hpp"

Point::Point() : FixedX( 0 ), FixedY( 0 ) {}

Point::Point( const float FixedX, const float FixedY ) : FixedX( FixedX ), FixedY( FixedY ) {}

Point::~Point() {}

Point::Point( const Point &other ) : FixedX( other.getFixedPointX() ), FixedY( other.getFixedPointY() ) {}

Point &Point::operator=( const Point &other )
{
    (void)other;
    return *this;
}

const Fixed &Point::getFixedPointX() const { return this->FixedX; }

const Fixed &Point::getFixedPointY() const { return this->FixedY; }