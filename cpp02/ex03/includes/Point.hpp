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
    const Fixed FixedX;
    const Fixed FixedY;

   public:
    Point();
    Point( const float FixedX, const float FixedY );
    Point( const Point &point );
    ~Point();
    Point &operator=( const Point &other );
    const Fixed &getFixedPointX() const;
    const Fixed &getFixedPointY() const;
};

#endif