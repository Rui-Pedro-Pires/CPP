/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiolive <ruiolive@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 12:48:51 by ruiolive          #+#    #+#             */
/*   Updated: 2024/05/08 14:05:33 by ruiolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/HumanA.hpp"

HumanA::HumanA( std::string name, Weapon& weapon ) : _name(name), _weapon(weapon)
{
}

HumanA::~HumanA()
{
}

void    HumanA::attack( void )
{
    std::cout << this->_name << " attacks with their weapon " << this->_weapon.getType() << std::endl;
}