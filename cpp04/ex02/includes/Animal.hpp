/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiolive  <ruiolive@student.42.fr   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 10:56:00 by ruiolive          #+#    #+#             */
/*   Updated: 2024/06/03 10:56:00 by ruiolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __ANIMAL_H__
#define __ANIMAL_H__

#include <iostream>
#define LOG(x) std::cout << x << std::endl;

class Animal
{
protected:
    std::string _type;

public:
    Animal();
    Animal( std::string type );
    virtual ~Animal();
    Animal( const Animal& other );
    Animal& operator=( const Animal& other );
    
    std::string getType() const;
    virtual void makeSound() const;
};

#endif