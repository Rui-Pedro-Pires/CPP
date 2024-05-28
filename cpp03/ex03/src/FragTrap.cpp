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

#include "../includes/FragTrap.hpp"

FragTrap::FragTrap()
{
    this->_name = "Unknown";
    this->_health = 100;
    this->_energy = 100;
    this->_attackDamage = 30;
    std::cout << "🤖 FragTrap " << this->_name << " was created" << std::endl;
}

FragTrap::FragTrap( std::string _name ) : ClapTrap( _name )
{
    this->_name = _name;
    this->_health = 100;
    this->_energy = 100;
    this->_attackDamage = 30;
    std::cout << "🤖 FragTrap " << this->_name << " was created" << std::endl;
}

FragTrap& FragTrap::operator=( const FragTrap& other )
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

FragTrap::FragTrap( const FragTrap& other ) : ClapTrap( other )
{
    this->_name = other._name;
    this->_health = other._health;
    this->_energy = other._energy;
    this->_attackDamage = other._attackDamage;
}

FragTrap::~FragTrap()
{
    std::cout << "🤖 FragTrap " << this->_name << " was destroyed" << std::endl;
}

void FragTrap::attack( const std::string& target )
{
    if ( this->_energy )
    {
        this->_energy--;
        std::cout << "⚔️ FragTrap " << this->_name << " attacks " << target << ", causing "
                  << ClapTrap::_attackDamage << " points of damage!" << std::endl;
        return;
    }
    std::cout << "🪫 No energy points left!" << std::endl;
}

void FragTrap::highFivesGuys( void )
{
    std::cout << "🙏 FragTrap " << this->_name << " highfive" << std::endl;
}