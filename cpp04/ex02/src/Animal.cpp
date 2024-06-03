/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiolive  <ruiolive@student.42.fr   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 10:55:36 by ruiolive          #+#    #+#             */
/*   Updated: 2024/06/03 10:55:36 by ruiolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Animal.hpp"

Animal::Animal()
{
    LOG("Animal constructed!");
    this->_type = "Animal";
}

Animal::Animal( std::string type )
{
    LOG("Animal constructed!");
    this->_type = type;
}

Animal::~Animal()
{
    LOG("Animal destructed!");
}

Animal::Animal( const Animal& other )
{
    this->_type = other._type;
}

Animal& Animal::operator=( const Animal& other )
{
    if ( this != &other )
    {
        this->_type = other._type;
    }
    return *this;
}

std::string Animal::getType() const
{
    return this->_type;
}

void Animal::makeSound() const
{
   std::cout << "     ██  ██████  ██████   ██████  ███████ " << std::endl;
   std::cout << "     ██ ██    ██ ██   ██ ██       ██      " << std::endl;
   std::cout << "     ██ ██    ██ ██████  ██   ███ █████   " << std::endl;
   std::cout << "██   ██ ██    ██ ██   ██ ██    ██ ██      " << std::endl;
   std::cout << " █████   ██████  ██   ██  ██████  ███████ " << std::endl;
   std::cout << std::endl;
}
