/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiolive  <ruiolive@student.42.fr   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 16:44:31 by ruiolive          #+#    #+#             */
/*   Updated: 2024/06/03 16:44:31 by ruiolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __ICHARACTER_H__
#define __ICHARACTER_H__

#include <iostream>

#include "AMateria.hpp"
#include "ICharacter.hpp"

class AMateria;

class ICharacter
{
public:
    virtual ~ICharacter(){};
    virtual std::string const& getName() const = 0;
    virtual void equip( AMateria* m ) = 0;
    virtual void unequip( int idx ) = 0;
    virtual void use( int idx, ICharacter& target ) = 0;
};

#endif