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

#include <fstream>
#include <iostream>
#include <string>

int main( int argc, char **argv )
{
    if ( argc != 4 )
    {
        std::cerr << "error" << std::endl;
        return ( 0 );
    }
    std::string buffer;
    std::string s1 = argv[2];
    std::string s2 = argv[3];
    std::ifstream file( argv[1] );
    std::ofstream newFile( "replace.txt" );
    std::size_t pos;
    if ( !file.is_open() )
    {
        std::cerr << "Error opening the file" << std::endl;
        return ( 0 );
    }
    while ( file.good() )
    {
        std::getline( file, buffer );
        pos = buffer.find( s1 );
        while ( pos != std::string::npos )
        {
            std::string bfrBuffer = buffer.substr( 0, pos );
            std::string aftBuffer = buffer.substr( pos + s2.length() );
            buffer = bfrBuffer + s2 + aftBuffer;
            pos = buffer.find( s1 );
        }
        newFile << buffer << std::endl;
    }
}