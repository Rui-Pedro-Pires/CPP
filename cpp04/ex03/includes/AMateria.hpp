/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiolive  <ruiolive@student.42.fr   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 16:41:45 by ruiolive          #+#    #+#             */
/*   Updated: 2024/06/03 16:41:45 by ruiolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __AMATERIA_H__
#define __AMATERIA_H__

#include <iostream>

#include "ICharacter.hpp"

class ICharacter;
class AMateria
{
protected:
    std::string _type;

public:
    AMateria();
    AMateria( std::string const& type );
    virtual ~AMateria();
    AMateria( const AMateria& originalAMateria );
    AMateria& operator=( const AMateria& originalAMateria );

    std::string const& getType() const;
    virtual AMateria* clone() const = 0;
    virtual void use( ICharacter& target );
};

#endif