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

#include "../includes/Brain.hpp"

Dog::Dog() : Animal( "Dog" )
{
    this->_brain = new Brain();
    LOG( "Dog constructed!" );
}

Dog::~Dog()
{
    delete this->_brain;
    LOG( "Dog destructed!" );
}

Dog::Dog( const Dog& other ) : Animal( other ), _brain( new Brain )
{
    this->_type = other._type;
    *this->_brain = *other._brain;
}

Dog& Dog::operator=( const Dog& other )
{
    if ( this != &other )
    {
        this->_type = other._type;
        *this->_brain = *other._brain;
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
