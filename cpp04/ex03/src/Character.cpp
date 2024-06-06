/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiolive  <ruiolive@student.42.fr   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 11:37:44 by ruiolive          #+#    #+#             */
/*   Updated: 2024/06/05 11:37:44 by ruiolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Character.hpp"

Character::Character()
{
    std::cout << "Character constructed!" << std::endl;
}

Character::Character( std::string const& name )
{
    std::cout << "Character constructed!" << std::endl;
    this->_name = name;
    this->_idx = 0;
    for ( int i = 0; i < 4; i++ )
    {
        this->materials[i] = NULL;
    }
}

Character::Character( const Character& originalCharacter )
{
    this->_name = originalCharacter._name;
    this->_idx = originalCharacter._idx;
    for ( int i = 0; i <= originalCharacter._idx; i++ )
    {
        if ( originalCharacter.materials[i] )
            this->materials[i] = originalCharacter.materials[i]->clone();
    }
}

Character& Character::operator=( const Character& originalCharacter )
{
    if ( this != &originalCharacter )
    {
        this->_name = originalCharacter._name;
        this->_idx = originalCharacter._idx;
        for ( int i = 0; i <= this->_idx; i++ )
        {
            if ( this->materials[i] )
            {
                delete this->materials[i];
                this->materials[i] = NULL;
            }
        }
        for ( int i = 0; i <= originalCharacter._idx; i++ )
        {
            if ( originalCharacter.materials[i] )
                this->materials[i] = originalCharacter.materials[i]->clone();
        }
    }
    return *this;
}

Character::~Character()
{
    std::cout << "Character destructed!" << std::endl;
    for ( int i = 0; i <= this->_idx; i++ )
    {
        if ( this->materials[i] )
            delete this->materials[i];
    }
}

void Character::use( int idx, ICharacter& target )
{
    if ( idx >= 0 && idx < 4 )
    {
        if ( this->materials[idx] )
            this->materials[idx]->use( target );
    }
}

void Character::unequip( int idx )
{
    if ( idx > 0 && idx < 4 )
    {
        if ( this->materials[idx] )
        {
            delete this->materials[idx];
            this->materials[idx] = NULL;
        }
    }
}

void Character::equip( AMateria* m )
{
    if ( this->_idx < 4 )
    {
        this->materials[this->_idx] = m;
        this->_idx++;
    }
}

std::string const& Character::getName() const
{
    return this->_name;
}