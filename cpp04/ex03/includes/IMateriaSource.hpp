/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiolive  <ruiolive@student.42.fr   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 18:02:37 by ruiolive          #+#    #+#             */
/*   Updated: 2024/06/05 18:02:37 by ruiolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __IMATERIASOURCE_H__
#define __IMATERIASOURCE_H__

#include "AMateria.hpp"

class IMateriaSource
{
public:
    virtual ~IMateriaSource(){};
    virtual void learnMateria( AMateria* ) = 0;
    virtual AMateria* createMateria( std::string const& type ) = 0;
};

#endif