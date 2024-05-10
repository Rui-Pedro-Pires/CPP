/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiolive  <ruiolive@student.42.fr   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 15:34:55 by ruiolive          #+#    #+#             */
/*   Updated: 2024/05/08 15:34:55 by ruiolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Sed.hpp"

int main(int argc, char **argv)
{
    if ( argc != 4 )
    {
        std::cerr << "Syntax: <file_to_replace> <string_to_change> <string_to_insert>" << std::endl;
        return ( 1 );
    }
    std::string s1 = argv[2];
    std::string s2 = argv[3];
    if (s1.empty() || s2.empty() || s1 == s2)
    {
        std::cerr << "Invalid arguments: no empty or equal arguments allowed!" << std::endl;
        return ( 1 );
    }
    if (sedFile( s1, s2, argv[1] ))
        return ( 1 );
    return ( 0 );
}