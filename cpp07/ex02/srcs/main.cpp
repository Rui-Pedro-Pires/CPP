/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiolive  <ruiolive@student.42.fr   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 16:11:26 by ruiolive          #+#    #+#             */
/*   Updated: 2024/10/04 16:11:26 by ruiolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>

#include "../includes/Array.hpp"

#define MAX_VAL 10
int main( int, char** )
{
    Array<int> numbers( MAX_VAL );
    int* mirror = new int[MAX_VAL];
    srand( time( NULL ) );
    for ( int i = 0; i < MAX_VAL; i++ )
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    // SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test( tmp );
        Array<int> t1;
        t1 = test;
    }

    for ( int i = 0; i < MAX_VAL; i++ )
    {
        if ( mirror[i] != numbers[i] )
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
        std::cout << "number[" << i << "]:" << numbers[i] << std::endl;
        std::cout << "mirror[" << i << "]:" << mirror[i] << std::endl;
    }
    try
    {
        numbers[-2] = 0;
    }
    catch ( const std::exception& e )
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch ( const std::exception& e )
    {
        std::cerr << e.what() << '\n';
    }
    for ( int i = 0; i < MAX_VAL; i++ )
    {
        numbers[i] = rand();
    }
    delete[] mirror;
    return 0;
}