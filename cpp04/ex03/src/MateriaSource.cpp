/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiolive  <ruiolive@student.42.fr   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 18:02:58 by ruiolive          #+#    #+#             */
/*   Updated: 2024/06/05 18:02:58 by ruiolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    std::cout << "MateriaSource constructed!" << std::endl;
    this->_idx = 0;
    for ( int i = 0; i < 4; i++ )
    {
        this->_inventory[i] = NULL;
    }
}

MateriaSource::~MateriaSource()
{
    std::cout << "MateriaSource destruted!" << std::endl;
    for ( int i = 0; i <= this->_idx; i++ )
    {
        if ( this->_inventory[i] )
            delete this->_inventory[i];
    }
}

MateriaSource::MateriaSource( const MateriaSource& originalMateralSource )
{
    this->_idx = originalMateralSource._idx;
    for ( int i = 0; i <= originalMateralSource._idx; i++ )
    {
        if ( originalMateralSource._inventory[i] )
            this->_inventory[i] = originalMateralSource._inventory[i]->clone();
    }
}

MateriaSource& MateriaSource::operator=( const MateriaSource& originalMateralSource )
{
    if ( this != &originalMateralSource )
    {
        this->_idx = originalMateralSource._idx;
        for ( int i = 0; i <= this->_idx; i++ )
        {
            if ( this->_inventory[i] )
            {
                delete this->_inventory[i];
                this->_inventory[i] = NULL;
            }
        }
        for ( int i = 0; i <= originalMateralSource._idx; i++ )
        {
            if ( originalMateralSource._inventory[i] )
                this->_inventory[i] = originalMateralSource._inventory[i]->clone();
        }
    }
    return *this;
}

void MateriaSource::learnMateria( AMateria* materia )
{
    if ( this->_idx < 4 )
    {
        this->_inventory[this->_idx] = materia;
        this->_idx++;
    }
}

AMateria* MateriaSource::createMateria( std::string const& type )
{
    for ( int i = 0; i <= this->_idx; i++ )
    {
        if ( this->_inventory[i] && this->_inventory[i]->getType() == type )
        {
            return this->_inventory[i]->clone();
        }
    }
    return NULL;
}