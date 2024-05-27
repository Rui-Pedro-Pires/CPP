/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiolive  <ruiolive@student.42.fr   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 14:04:25 by ruiolive          #+#    #+#             */
/*   Updated: 2024/05/23 14:04:25 by ruiolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"

ClapTrap::ClapTrap()
{
    this->_name = "Unknown";
    this->_health = 10;
    this->_energy = 10;
    this->_attackDamage = 0;
    std::cout << "ClapTrap " << this->_name << " created!" << std::endl;
}

ClapTrap::ClapTrap( std::string _name )
{
    this->_name = _name;
    this->_health = 10;
    this->_energy = 10;
    this->_attackDamage = 0;
    std::cout << "ClapTrap " << this->_name << " created!" << std::endl;
}

ClapTrap::ClapTrap( const ClapTrap& other )
{
    this->_name = other._name;
    this->_health = other._health;
    this->_energy = other._energy;
    this->_attackDamage = other._attackDamage;
}

ClapTrap& ClapTrap::operator=( const ClapTrap& other )
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

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap " << this->_name << " destroyed!" << std::endl;
}

void ClapTrap::attack( const std::string& target )
{
    if ( this->_energy )
    {
        this->_energy--;
        std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing "
                  << this->_attackDamage << " points of damage!" << std::endl;
    }
    else
        std::cout << "No energy points left!" << std::endl;
}

void ClapTrap::attackTarget( ClapTrap& target )
{
    if ( target._health <= 0 )
    {
        if ( this->_energy )
            this->_energy--;
        else
        {
            std::cout << "No energy points left!" << std::endl;
            return;
        }
        std::cout << this->_name << " tried to attack " << target._name << " but ";
        std::cout << target._name << " is already dead!" << std::endl;
    }
    else if ( !this->_attackDamage )
    {
        if ( this->_energy )
            this->_energy--;
        else
        {
            std::cout << "No energy points left!" << std::endl;
            return;
        }
        std::cout << this->_name << " tried to attack but as missed the shot!" << std::endl;
        std::cout << "No damage made!" << std::endl;
    }
    else
    {
        this->attack( target._name );
        target.takeDamage( this->_attackDamage );
    }
}

void ClapTrap::takeDamage( unsigned int amount )
{
    this->_health -= amount;
    std::cout << this->_name << " lost " << amount << " of health" << std::endl;
    if ( this->_health <= 0 )
        std::cout << this->_name << " is dead!" << std::endl;
}

void ClapTrap::beRepaired( unsigned int amount )
{
    if ( this->_energy )
    {
        this->_energy--;
        this->_health += amount;
        std::cout << this->_name << " gained " << amount << " of health!" << std::endl;
    }
    else
        std::cout << "No energy points left!" << std::endl;
}

void ClapTrap::setAttackDamage( unsigned int amount )
{
    this->_attackDamage = amount;
    std::cout << this->_name << " is reloading the weapon " << std::endl;
}