/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiolive  <ruiolive@student.42.fr   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 14:04:54 by ruiolive          #+#    #+#             */
/*   Updated: 2024/05/23 14:07:14 by ruiolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __CLAPTRAP_H__
#define __CLAPTRAP_H__

#include <iostream>

class ClapTrap
{
protected:
    std::string _name;
    unsigned int _health;
    unsigned int _energy;
    unsigned int _attackDamage;

public:
    ClapTrap();
    ClapTrap( std::string _name );
    ClapTrap( const ClapTrap& other );
    ~ClapTrap();
    ClapTrap& operator=( const ClapTrap& other );
    virtual void attack( const std::string& target );
    void attackTarget( ClapTrap& target );
    void takeDamage( unsigned int amount );
    void beRepaired( unsigned int amount );
    void setAttackDamage( unsigned int amount );
};

#endif