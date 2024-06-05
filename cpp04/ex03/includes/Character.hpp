/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiolive  <ruiolive@student.42.fr   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 11:34:50 by ruiolive          #+#    #+#             */
/*   Updated: 2024/06/05 11:34:50 by ruiolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __CHARACTER_H__
#define __CHARACTER_H__

#include "ICharacter.hpp"
#include "Character.hpp"

class Character : public ICharacter
{
private:
    std::string _name;
    AMateria* materials[4];
    int _idx;
    Character();

public:
    Character( std::string const& name );
    ~Character();
    Character( const Character& originalCharacter );
    Character& operator=( const Character& originalCharacter );
    void use(int idx, ICharacter& target);
    void unequip(int idx);
    void equip(AMateria* m);
    std::string const & getName() const;
};

#endif