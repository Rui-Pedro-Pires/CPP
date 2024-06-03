/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiolive  <ruiolive@student.42.fr   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 11:16:33 by ruiolive          #+#    #+#             */
/*   Updated: 2024/06/03 11:16:33 by ruiolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __CAT_H__
#define __CAT_H__

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
private:
    Brain* _brain;

public:
    Cat();
    ~Cat();
    Cat( const Cat& other );
    Cat& operator=( const Cat& other );

    void makeSound() const;
    void addIdea( std::string idea );
    void printIdeas() const;
};

#endif