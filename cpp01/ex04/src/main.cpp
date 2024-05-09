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

int main(int argc, char **argv)
{
    if ( argc != 4 )
    {
        std::cerr << "Syntax: <file_to_replace> <string_to_change> <string_to_insert>" << std::endl;
        return ( 0 );
    }
    std::size_t pos;
    std::string buffer;
    std::string newBuffer;
    std::string s1 = argv[2];
    std::string s2 = argv[3];
    std::ifstream file( argv[1] );
    if ( !file.is_open() )
    {
        std::cerr << "Error opening the file" << std::endl;
        return ( 0 );
    }
    std::ofstream newFile( (std::string(argv[1]) + ".replace").c_str() );
    if ( !newFile.is_open() )
    {
        std::cerr << "Error creating the file" << std::endl;
        return ( 0 );
    }
    while ( std::getline( file, buffer ) )
    {
        pos = buffer.find( s1 );
        while ( pos != std::string::npos )
        {
            std::string bfrBuffer = buffer.substr( 0, pos );
            newBuffer = bfrBuffer + s2;
            buffer = buffer.substr(pos + s1.length(), buffer.length() - pos - s1.length());
            pos = buffer.find( s1 );
        }
        newBuffer += buffer;
        if (!file.eof())
            newFile << newBuffer << std::endl;
        else
            newFile << newBuffer;
        newBuffer = "";
    }
}