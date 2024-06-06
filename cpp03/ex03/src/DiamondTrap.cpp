/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiolive  <ruiolive@student.42.fr   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 13:00:57 by ruiolive          #+#    #+#             */
/*   Updated: 2024/05/27 13:00:57 by ruiolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap(), FragTrap(), ScavTrap()
{
    this->_name = "Unknown";
    FragTrap::_health = 100;
    ScavTrap::_energy = 50;
    FragTrap::_attackDamage = 30;
    std::cout << "🤖 DiamondTrap " << this->_name << " was created" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string _name)
    : ClapTrap(_name + "_clap_name"), FragTrap(_name + "_clap_name"), ScavTrap(_name + "_clap_name")
{
    this->_name = _name;
    ClapTrap::_name = _name + "_clap_name";
    FragTrap::_health = 100;
    ScavTrap::_energy = 50;
    FragTrap::_attackDamage = 30;
    std::cout << "🤖 DiamondTrap " << this->_name << " was created" << std::endl;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "🤖 DiamondTrap " << this->_name << " was destroyed" << std::endl;
}

void DiamondTrap::whoiam(void)
{
    std::cout << "👀 My ClapTrap name is " << ClapTrap::_name << std::endl;
    std::cout << "👀 My DiamondTrap name is " << this->_name << std::endl;
}