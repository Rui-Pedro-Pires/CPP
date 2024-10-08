/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiolive  <ruiolive@student.42.fr   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 12:16:45 by ruiolive          #+#    #+#             */
/*   Updated: 2024/10/07 12:16:45 by ruiolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Span.hpp"

int main( int, char ** )
{
    srand( time( 0 ) );
    Span sp = Span( 5 );
    sp.addNumber( 6 );
    sp.addNumber( 8 );
    sp.addNumber( 17 );
    sp.addNumber( 9 );
    sp.addNumber( 11 );
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
    int *arr = new int[10000];
    if ( !arr )
        return ( 0 );
    for ( int i = 0; i < 10000; i++ )
    {
        arr[i] = rand() % 10000;
    }
    try
    {
        Span sp2 = Span( 10000 );
        sp2.addManyNumbers( arr, 10000 );
        std::cout << sp2.shortestSpan() << std::endl;
        std::cout << sp2.longestSpan() << std::endl;
    }
    catch ( const std::exception &e )
    {
        std::cerr << e.what() << '\n';
    }
    delete[] arr;
    return 0;
}