/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiolive  <ruiolive@student.42.fr   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 10:22:04 by ruiolive          #+#    #+#             */
/*   Updated: 2024/05/10 10:22:07 by ruiolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Sed.hpp"

int    sedFile( std::string s1, std::string s2 , char *argv )
{

    std::size_t pos;
    std::string buffer;
    std::string newBuffer;
    std::ifstream file( argv );
    if ( !file.is_open() )
    {
        std::cerr << "Error opening the file" << std::endl;
        return ( 1 );
    }
    std::ofstream newFile( (std::string(argv) + ".replace").c_str() );
    if ( !newFile.is_open() )
    {
        std::cerr << "Error creating the file" << std::endl;
        return ( 1 );
    }
    while ( file.good() )
    {
        newBuffer = file.get();
        if (!file.eof())
            buffer += newBuffer;
    }
    pos = buffer.find( s1 );
    while ( pos != std::string::npos )
    {
        try {
            buffer.erase(pos, s1.length());
            buffer.insert(pos, s2);
        }
        catch (std::out_of_range&){
            std::cerr << "Out of range in buffer" << std::endl;
        }
        catch (std::length_error&) {
            std::cerr << "Length error in buffer" << std::endl;
        }
        pos = buffer.find( s1 );
    }
    newFile << buffer;
    return ( 0 );
}
