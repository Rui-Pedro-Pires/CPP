/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiolive  <ruiolive@student.42.fr   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 13:50:34 by ruiolive          #+#    #+#             */
/*   Updated: 2024/05/21 13:50:34 by ruiolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"
#include "../includes/Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point );
void    pointInsideTriangle(const Point a, const Point b, const Point c, const Point point);

int main( void )
{
    Point pointA1( 0.0, 0.0 );
    Point pointB1( 0.0, 4.0 );
    Point pointC1( 4.0, 0.0 );
    Point midPoint1( 2.0, 1.0);

    Point pointA2( 0.0, 0.0 );
    Point pointB2( 0.0, 1.0 );
    Point pointC2( 0.0, 1.0 );
    Point midPoint2( 2.0, 1.0);

    Point pointA3( 0.0, 0.0 );
    Point pointB3( 0.0, 4.0 );
    Point pointC3( 4.0, 0.0 );
    Point midPoint3( 4.0, 4.0);

    pointInsideTriangle(pointA1, pointB1, pointC1, midPoint1);
    pointInsideTriangle(pointA2, pointB2, pointC2, midPoint2);
    pointInsideTriangle(pointA3, pointB3, pointC3, midPoint3);
    return 0;
}