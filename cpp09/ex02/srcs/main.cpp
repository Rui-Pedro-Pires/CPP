/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiolive  <ruiolive@student.42.fr   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 12:16:46 by ruiolive          #+#    #+#             */
/*   Updated: 2024/10/07 12:16:46 by ruiolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PmergeMe.hpp"

int main()
{
    srand( time( 0 ) );
    std::vector<int> numbers;
    clock_t start, end;
    for ( int i = 0; i < 200; i++ )
    {
        numbers.push_back( rand() % 100000 );
        std::cout << numbers[i] << std::endl;
    }
    PmergeMe num( numbers );

    std::cout << "Before: ";
    num.printList( "main" );
    std::cout << std::endl;

    start = clock();

    num.mergeSort( 0, num.getSizeMain() - 1 );
    num.insert();

    end = clock();

    std::cout << "After: ";
    num.printList( "main" );
    std::cout << std::endl;

    double time_taken = double( end - start ) / double( CLOCKS_PER_SEC );
    std::cout << "Time to process a range of 200 elements with std::vector : " << std::fixed
              << time_taken << std::setprecision( 5 ) << std::endl;
}