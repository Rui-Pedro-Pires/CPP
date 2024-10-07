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
    int pos;
    std::vector<int> vec( 10 );
    for ( int i = 0; i < 10; i++ )
    {
        vec.push_back( i );
    }
    try
    {
        pos = easyfind( vec, 2 );
        std::cout << pos << std::endl;
    }
    catch ( const std::exception& e )
    {
        std::cerr << e.what() << '\n';
    }
}