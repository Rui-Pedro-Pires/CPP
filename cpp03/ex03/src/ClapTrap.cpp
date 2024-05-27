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
        return;
    }
    std::cout << "No energy points left!" << std::endl;
}

void ClapTrap::attackTarget( ClapTrap& target )
{
    if (!this->_attackDamage)
    {
        this->attack(target._name);
        std::cout << "No damage made!" << std::endl;
        target.takeDamage(this->_attackDamage);
        return ;
    }
    this->attack(target._name);
    target.takeDamage(this->_attackDamage);
}

void ClapTrap::takeDamage( unsigned int amount )
{
    this->_health -= amount;
    std::cout << this->_name << " lost " << amount << " of health" << std::endl;
}

void ClapTrap::beRepaired( unsigned int amount )
{
    if ( this->_energy )
    {
        this->_energy--;
        this->_health += amount;
        std::cout << this->_name << " gained " << amount << " of health!"
                  << std::endl;
        return;
    }
    std::cout << "No energy points left!" << std::endl;
}

void ClapTrap::setAttackDamage( unsigned int amount )
{
    this->_attackDamage = amount;
}
