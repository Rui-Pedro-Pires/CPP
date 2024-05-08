/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiolive <ruiolive@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 12:48:20 by ruiolive          #+#    #+#             */
/*   Updated: 2024/05/08 13:52:26 by ruiolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Weapon.hpp"

Weapon::Weapon()
{
}

Weapon::Weapon( std::string type )
{
    this->_type = type;
}

Weapon::~Weapon()
{
}

const std::string&  Weapon::getType()
{
    return (this->_type);
}

void    Weapon::setType( std::string type)
{
    this->_type = type;
}