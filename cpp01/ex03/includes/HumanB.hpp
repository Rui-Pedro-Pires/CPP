/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiolive <ruiolive@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 12:49:26 by ruiolive          #+#    #+#             */
/*   Updated: 2024/05/08 13:56:50 by ruiolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __HUMAN2_HPP__
#define __HUMAN2_HPP__

#include "Weapon.hpp"

class HumanB
{
    
public:

    HumanB( std::string name );
    HumanB( std::string name, Weapon &weapon );
    ~HumanB();
    void    attack( void );
    void    setWeapon( Weapon &weapon );
    
private:

    std::string _name;
    Weapon  *_weapon;

};

#endif