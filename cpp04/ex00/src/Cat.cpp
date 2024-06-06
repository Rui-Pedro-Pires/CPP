/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiolive  <ruiolive@student.42.fr   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 11:16:23 by ruiolive          #+#    #+#             */
/*   Updated: 2024/06/03 11:16:23 by ruiolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cat.hpp"

Cat::Cat() : Animal( "Cat" )
{
    LOG("Cat constructed!");
}

Cat::~Cat()
{
    LOG("Cat destructed!");
}

Cat::Cat( const Cat& other ) : Animal( other )
{
    std::cout << "copy constructer from cat called!" << std::endl;
    this->_type = other._type;
}

Cat& Cat::operator=( const Cat& other )
{
    if ( this != &other )
    {
        this->_type = other._type;
    }
    return *this;
}

void Cat::makeSound() const
{
    std::cout << "███    ███ ███████  ██████  ██     ██ " << std::endl;
    std::cout << "████  ████ ██      ██    ██ ██     ██ " << std::endl;
    std::cout << "██ ████ ██ █████   ██    ██ ██  █  ██ " << std::endl;
    std::cout << "██  ██  ██ ██      ██    ██ ██ ███ ██ " << std::endl;
    std::cout << "██      ██ ███████  ██████   ███ ███ " << std::endl;
    std::cout << std::endl;
}