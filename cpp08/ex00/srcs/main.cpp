/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiolive  <ruiolive@student.42.fr   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 12:16:43 by ruiolive          #+#    #+#             */
/*   Updated: 2024/10/07 12:16:43 by ruiolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/easyfind.hpp"

int main( int, char** )
{
    int arr[] = {1, 4, 2, 5, 7, 3, 9, 10};
    std::vector<int> vec(arr, arr + 8);
    std::list<int> list(arr, arr + 8);
    std::deque<int> deque(arr, arr + 8);
    try
    {
        std::cout << easyfind( vec, 10 ) << std::endl;
    }
    catch ( const std::exception& e )
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        std::cout << easyfind( list, 20 ) << std::endl;
    }
    catch ( const std::exception& e )
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        std::cout << easyfind( deque, 4 ) << std::endl;
    }
    catch ( const std::exception& e )
    {
        std::cerr << e.what() << '\n';
    }
}