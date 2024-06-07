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
    this->_garbageIdx = 0;
    for ( int i = 0; i < 4; i++ )
    {
        this->_inventory[i] = NULL;
        this->_garbage[i] = NULL;
    }
}

Character::Character( const Character& originalCharacter )
{
    this->_name = originalCharacter._name;
    this->_idx = originalCharacter._idx;
    this->_garbageIdx = 0;
    for ( int i = 0; i <= originalCharacter._idx; i++ )
    {
        if ( originalCharacter._inventory[i] )
            this->_inventory[i] = originalCharacter._inventory[i]->clone();
        if ( originalCharacter._garbage[i] )
            this->_garbage[i] = originalCharacter._garbage[i]->clone();
    }
}

Character& Character::operator=( const Character& originalCharacter )
{
    if ( this != &originalCharacter )
    {
        this->_name = originalCharacter._name;
        this->_idx = originalCharacter._idx;
        this->_garbageIdx = originalCharacter._garbageIdx;
        for ( int i = 0; i < 4; i++ )
        {
            if ( this->_inventory[i] )
            {
                delete this->_inventory[i];
                this->_inventory[i] = NULL;
            }
            if ( this->_garbage[i] )
            {
                delete this->_garbage[i];
                this->_garbage[i] = NULL;
            }
        }
        for ( int i = 0; i < 4; i++ )
        {
            if ( originalCharacter._inventory[i] )
                this->_inventory[i] = originalCharacter._inventory[i]->clone();
            if ( originalCharacter._garbage[i] )
                this->_garbage[i] = originalCharacter._garbage[i]->clone();
        }
    }
    return *this;
}

Character::~Character()
{
    std::cout << "Character destructed!" << std::endl;
    for ( int i = 0; i < 4; i++ )
    {
        if ( this->_inventory[i] )
            delete this->_inventory[i];
        if ( this->_garbage[i] )
            delete this->_garbage[i];
    }
}

void Character::use( int idx, ICharacter& target )
{
    if ( idx >= 0 && idx < 4 )
    {
        if ( this->_inventory[idx] )
            this->_inventory[idx]->use( target );
    }
}

void Character::unequip( int idx )
{
    if ( idx >= 0 && idx < 4 )
    {
        if ( this->_inventory[idx] )
        {
            if ( this->_garbageIdx < 4 )
            {
                this->_garbage[_garbageIdx] = this->_inventory[idx];
                this->_garbageIdx++;
            }
            else
            {
                this->_garbageIdx = 0;
                cleanGarbage();
                this->_garbage[_garbageIdx] = this->_inventory[idx];
                this->_garbageIdx++;
            }
            if (this->idx != 0)
                this->idx--;
            this->_inventory[idx] = NULL;
        }
    }
}

void Character::equip( AMateria* m )
{
    if ( this->_idx < 4 )
    {
        this->_inventory[this->_idx] = m;
        this->_idx++;
    }
    else
        delete m;
}

std::string const& Character::getName() const
{
    return this->_name;
}

void Character::cleanGarbage()
{
    for (int i = 0; i < 4; i++) {
        if (this->_garbage[i])
        {
            delete this->_garbage[i];
            this->_garbage[i] = NULL;
        }
    }
}
