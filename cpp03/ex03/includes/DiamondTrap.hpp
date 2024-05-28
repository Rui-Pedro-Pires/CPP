/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiolive  <ruiolive@student.42.fr   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 13:00:38 by ruiolive          #+#    #+#             */
/*   Updated: 2024/05/27 13:00:38 by ruiolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __DIAMONDTRAP_H__
#define __DIAMONDTRAP_H__

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
protected:
    std::string _name;
    using FragTrap::_attackDamage;
    using FragTrap::_health;
    using ScavTrap::_energy;

public:
    DiamondTrap();
    DiamondTrap( const std::string _name );
    DiamondTrap( const DiamondTrap& other );
    DiamondTrap& operator=( const DiamondTrap& other );
    ~DiamondTrap();
    void attack( const std::string& target );
    void whoiam( void );
};

#endif
