/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiolive <ruiolive@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 12:49:13 by ruiolive          #+#    #+#             */
/*   Updated: 2024/05/08 13:35:22 by ruiolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __WEAPON_HPP__
#define __WEAPON_HPP__

#include <iostream>

class Weapon
{
    
public:

    Weapon();
    Weapon( std::string type );
    ~Weapon();
    void    setType( std::string type );
    const std::string& getType( void );

private:

    std::string _type;
    
};

#endif