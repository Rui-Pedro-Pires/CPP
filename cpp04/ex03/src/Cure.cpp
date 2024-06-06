/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiolive  <ruiolive@student.42.fr   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 10:13:56 by ruiolive          #+#    #+#             */
/*   Updated: 2024/06/05 10:13:56 by ruiolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cure.hpp"

Cure::Cure() : AMateria( "cure" )
{
    std::cout << "Cure material constructed!" << std::endl;
}

Cure::~Cure()
{
    std::cout << "Ice material destructed!" << std::endl;
}

Cure::Cure( const Cure& originalIce ) : AMateria( originalIce )
{
}

Cure& Cure::operator=( const Cure& originalIce )
{
    if ( this != &originalIce )
    {
        this->_type = originalIce._type;
    }
    return *this;
}

AMateria* Cure::clone() const
{
    AMateria* materialReturn = new Cure();
    return materialReturn;
}

void Cure::use( ICharacter& target )
{
    std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}