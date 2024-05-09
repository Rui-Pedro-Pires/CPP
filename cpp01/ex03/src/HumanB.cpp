/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiolive <ruiolive@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 12:49:05 by ruiolive          #+#    #+#             */
/*   Updated: 2024/05/08 13:57:05 by ruiolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/HumanB.hpp"

HumanB::HumanB( std::string name )
{
    this->_name = name;
    this->_weapon = NULL;
}

HumanB::~HumanB()
{
}

void    HumanB::attack( void )
{
    if (this->_weapon)
        std::cout << this->_name << " attacks with their weapon " << this->_weapon->getType() << std::endl;
    else
        std::cout << this->_name << " attacks with their weapon " << "caoooooo" << std::endl;
}

void    HumanB::setWeapon( Weapon &weapon )
{
    this->_weapon = &weapon;
}
