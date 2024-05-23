/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiolive  <ruiolive@student.42.fr   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 14:26:18 by ruiolive          #+#    #+#             */
/*   Updated: 2024/05/22 14:26:18 by ruiolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"
#include "../includes/Point.hpp"

float area( Point a, Point b, Point c )
{
    float x1 = a.getFixedPointX().toFloat();
    float y1 = a.getFixedPointY().toFloat();
    float x2 = b.getFixedPointX().toFloat();
    float y2 = b.getFixedPointY().toFloat();
    float x3 = c.getFixedPointX().toFloat();
    float y3 = c.getFixedPointY().toFloat();
    float area = ( x1 * ( y2 - y3 ) + x2 * ( y1 - y3 ) + x3 * ( y1 - y2 ) ) / 2.0;
    if ( area < 0 )
        return area * -1;
    return area;
}

bool bsp( Point const a, Point const b, Point const c, Point const point )
{
    float mainArea = area( a, b, c );
    float aTriangulo = area( point, b, c );
    float bTriangulo = area( a, point, c );
    float cTriangulo = area( a, b, point );

    if ( aTriangulo == 0 || bTriangulo == 0 || cTriangulo == 0 )
        return ( false );
    return ( mainArea == ( aTriangulo + bTriangulo + cTriangulo ) );
}

void    pointInsideTriangle(const Point a, const Point b, const Point c, const Point point)
{
    if ( bsp( a, b, c, point ) )
    {
        LOG( "True" );
        return ;
    }
    LOG("False");
}
