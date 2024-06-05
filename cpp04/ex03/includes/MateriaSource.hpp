/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiolive  <ruiolive@student.42.fr   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 18:03:22 by ruiolive          #+#    #+#             */
/*   Updated: 2024/06/05 18:03:22 by ruiolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __MATERIASOURCE_H__
#define __MATERIASOURCE_H__

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
private:
    AMateria* materials[4];
    int _idx;
public:
    MateriaSource();
    ~MateriaSource();
    MateriaSource(const MateriaSource& originalMateriaSource);
    MateriaSource& operator=(const MateriaSource& originalMateriaSource);
    void learnMateria( AMateria* materia);
    AMateria* createMateria(std::string const & type); 
};

#endif