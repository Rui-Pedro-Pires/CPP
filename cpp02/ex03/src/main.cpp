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

int main( void )
{
    Point pointA( 0.0, 0.0 );
    Point pointB( 0.0, 4.0 );
    Point pointC( 4.0, 0.0 );
    Point midPoint( 2.0, 1.0);

    if ( bsp( pointA, pointB, pointC, midPoint ) )
    {
        LOG( "True" );
        return (0);
    }
    LOG("False");
    return 0;
}