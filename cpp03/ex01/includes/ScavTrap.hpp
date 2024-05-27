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
#ifndef __SCAVTRAP_H__
#define __SCAVTRAP_H__


#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
public:
    ScavTrap();
    ScavTrap( std::string _name );
    ScavTrap( const ScavTrap& other );
    ~ScavTrap();
    ScavTrap& operator=( const ScavTrap& other );
    void guardGate( void );
    void attack( const std::string& target );
};

#endif