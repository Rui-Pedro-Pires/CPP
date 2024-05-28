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

ScavTrap& ScavTrap::operator=( const ScavTrap& other )
{
    if ( this != &other )
    {
        this->_name = other._name;
        this->_health = other._health;
        this->_energy = other._energy;
        this->_attackDamage = other._attackDamage;
    }
    return *this;
}

ScavTrap::ScavTrap( const ScavTrap& other ) : ClapTrap( other )
{
    this->_name = other._name;
    this->_health = other._health;
    this->_energy = other._energy;
    this->_attackDamage = other._attackDamage;
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
                  << ClapTrap::_attackDamage << " points of damage!" << std::endl;
        return;
    }
    std::cout << "🪫 No energy points left!" << std::endl;
}
