/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiolive  <ruiolive@student.42.fr   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 10:52:00 by ruiolive          #+#    #+#             */
/*   Updated: 2024/05/27 10:52:00 by ruiolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef FRAGTRAP_H__
#define FRAGTRAP_H__

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
protected:
    int _health;
    unsigned int _energy;
    unsigned int _attackDamage;

public:
    FragTrap();
    FragTrap( std::string _name );
    FragTrap( const FragTrap& other );
    ~FragTrap();
    FragTrap& operator=( const FragTrap& other );
    void attack( const std::string& target );
    void highFivesGuys( void );
};

#endif