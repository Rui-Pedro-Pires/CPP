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

DiamondTrap::DiamondTrap() : FragTrap(), ScavTrap()
{
    this->_name = "Bino";
    this->_health = FragTrap::_health;
    this->_energy = ScavTrap::_health;
    this->_attackDamage = FragTrap::_attackDamage;
    std::cout << "DiamondTrap " << this->_name << " was created" << std::endl;
}

DiamondTrap::DiamondTrap( const std::string _name )
    : FragTrap( _name + "_clap_name" ), ScavTrap( _name + "_clap_name" )
{
    this->_name = _name;
    this->_health = FragTrap::_health;
    this->_energy = ScavTrap::_health;
    this->_attackDamage = FragTrap::_attackDamage;
    std::cout << "DiamondTrap " << this->_name << " was created" << std::endl;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap " << this->_name << " was destroyed" << std::endl;
}

DiamondTrap::DiamondTrap( const DiamondTrap& other )
    : ClapTrap( other ), FragTrap( other ), ScavTrap( other )
{
    this->_name = other._name;
    this->_health = other._health;
    this->_energy = other._energy;
    this->_attackDamage = other._attackDamage;
}

DiamondTrap& DiamondTrap::operator=( const DiamondTrap& other )
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

void DiamondTrap::attack( const std::string& target )
{
    ScavTrap::attack( target );
}

void DiamondTrap::whoiam( void )
{
    std::cout << "My ClapTrap name is " << ClapTrap::_name << std::endl;
    std::cout << "My DiamondTrap name is " << this->_name << std::endl;
}