/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiolive  <ruiolive@student.42.fr   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 16:58:51 by ruiolive          #+#    #+#             */
/*   Updated: 2024/06/03 16:58:51 by ruiolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AMateria.hpp"

AMateria::AMateria()
{
}

AMateria::AMateria( std::string const& type )
{
    std::cout << "Materia constructed!" << std::endl;
    this->_type = type;
}

AMateria::~AMateria()
{
    std::cout << "Materia destructed!" << std::endl;
}

AMateria::AMateria( const AMateria& originalAMateria )
{
    this->_type = originalAMateria._type;
}

AMateria& AMateria::operator=( const AMateria& originalAMateria )
{
    if ( this != &originalAMateria )
    {
        this->_type = originalAMateria._type;
    }
    return *this;
}

std::string const& AMateria::getType() const
{
    return this->_type;
}

void AMateria::use( ICharacter& target )
{
    std::cout << "No materia to use on " << target.getName() << "!" << std::endl;
}