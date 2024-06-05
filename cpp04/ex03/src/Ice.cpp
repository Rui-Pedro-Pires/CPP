/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiolive  <ruiolive@student.42.fr   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 10:14:03 by ruiolive          #+#    #+#             */
/*   Updated: 2024/06/05 10:14:03 by ruiolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Ice.hpp"

Ice::Ice() : AMateria( "ice" )
{
    std::cout << "Ice material constructed!" << std::endl;
}

Ice::~Ice()
{
    std::cout << "Ice material destructed!" << std::endl;
}

Ice::Ice( const Ice& originalIce ) : AMateria( originalIce._type )
{
}

Ice& Ice::operator=( const Ice& originalIce )
{
    if ( this != &originalIce )
    {
        this->_type = originalIce._type;
    }
    return *this;
}

AMateria* Ice::clone() const
{
    AMateria* materialReturn = new Ice();
    return materialReturn;
}

void Ice::use( ICharacter& target )
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}