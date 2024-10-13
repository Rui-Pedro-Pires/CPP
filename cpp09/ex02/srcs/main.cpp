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
    for ( int i = 0; i < 11; i++ )
    {
        numbers.push_back( rand() % 100 );
        std::cout << numbers[i] << std::endl;
    }
    PmergeMe num( numbers );

    std::cout << "-----------" << std::endl;
    num.mergeSort( 0, num.getSizeMain() - 1 );
    num.inserting();
    num.printList( "main" );
}