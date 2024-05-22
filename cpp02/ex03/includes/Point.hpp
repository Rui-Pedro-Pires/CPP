/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiolive  <ruiolive@student.42.fr   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 14:18:17 by ruiolive          #+#    #+#             */
/*   Updated: 2024/05/22 14:18:17 by ruiolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __POINT_H__
#define __POINT_H__

#include <cmath>
#include <iostream>

#include "Fixed.hpp"

class Point
{
   private:
    Fixed const FixedX;
    Fixed const FixedY;

   public:
    Point();
    Point( const float FixedX, const float FixedY );
    Point( const Point &point );
    ~Point();
    const Point &operator=( const Point &other );
    const Fixed &getFixedPointX() const;
    const Fixed &getFixedPointY() const;
};

bool bsp( Point const a, Point const b, Point const c, Point const point );

#endif