/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiolive <ruiolive@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 12:49:19 by ruiolive          #+#    #+#             */
/*   Updated: 2024/05/08 14:05:42 by ruiolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __HUMAN1_HPP__
#define __HUMAN1_HPP__

#include "Weapon.hpp"

class HumanA
{

public:

    HumanA( std::string name, Weapon &weapon);
    ~HumanA();
    void    attack( void );
    
private:

    std::string _name;
    Weapon &_weapon;

};


#endif