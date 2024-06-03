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

class ICharacter
{
private:
public:
    ICharacter();
    ~ICharacter();
    ICharacter( const ICharacter& originalICharacter );
    ICharacter& operator=( const ICharacter& originalICharacter );
};

#endif