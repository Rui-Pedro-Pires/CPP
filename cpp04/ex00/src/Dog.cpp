/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiolive  <ruiolive@student.42.fr   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 11:16:29 by ruiolive          #+#    #+#             */
/*   Updated: 2024/06/03 11:16:29 by ruiolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Dog.hpp"

Dog::Dog() : Animal( "Dog" )
{
    LOG("Dog constructed!");
}

Dog::~Dog()
{
    LOG("Dog destructed!");
}

Dog::Dog( const Dog& other ) : Animal( other )
{
    this->_type = other._type;
}

Dog& Dog::operator=( const Dog& other )
{
    if ( this != &other )
    {
        this->_type = other._type;
    }
    return *this;
}

void Dog::makeSound() const
{
    std::cout << "██     ██  ██████   ██████  ███████ " << std::endl;
    std::cout << "██     ██ ██    ██ ██    ██ ██      " << std::endl;
    std::cout << "██  █  ██ ██    ██ ██    ██ █████   " << std::endl;
    std::cout << "██ ███ ██ ██    ██ ██    ██ ██      " << std::endl;
    std::cout << " ███ ███   ██████   ██████  ██      " << std::endl;
    std::cout << std::endl;
}