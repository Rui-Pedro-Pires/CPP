/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiolive  <ruiolive@student.42.fr   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 10:52:08 by ruiolive          #+#    #+#             */
/*   Updated: 2024/05/27 10:52:08 by ruiolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScavTrap.hpp"

ScavTrap::ScavTrap()
{
    this->_name = "Unknown";
    this->_health = 100;
    this->_energy = 50;
    this->_attackDamage = 20;
    std::cout << "🤖 ScavTrap " << this->_name << " was created" << std::endl;
}

ScavTrap::ScavTrap( std::string _name ) : ClapTrap( _name )
{
    this->_name = _name;
    this->_health = 100;
    this->_energy = 50;
    this->_attackDamage = 20;
    std::cout << "🤖 ScavTrap " << this->_name << " was created" << std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout << "🤖 ScavTrap " << this->_name << " was destroyed" << std::endl;
}

void ScavTrap::guardGate( void )
{
    std::cout << "🛡️ " << this->_name << " is now in gatekeeper mode!" << std::endl;
}

void ScavTrap::attack( const std::string& target )
{
    if ( this->_energy )
    {
        this->_energy--;
        std::cout << "⚔️ ScavTrap " << this->_name << " attacks " << target << ", causing "
                  << this->_attackDamage << " points of damage!" << std::endl;
        return;
    }
    std::cout << "🪫 No energy points left!" << std::endl;
}
