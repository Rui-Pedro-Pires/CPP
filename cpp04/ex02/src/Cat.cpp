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
    LOG( "Cat constructed!" );
    this->_brain = new Brain();
}

Cat::~Cat()
{
    delete this->_brain;
    LOG( "Cat destructed!" );
}

Cat::Cat( const Cat& other ) : Animal( other ), _brain( new Brain )
{
    this->_type = other._type;
    *this->_brain = *other._brain;
}

Cat& Cat::operator=( const Cat& other )
{
    if ( this != &other )
    {
        this->_type = other._type;
        *this->_brain = *other._brain;
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

void Cat::addIdea( std::string idea )
{
    this->_brain->createIdea( idea );
}

void Cat::printIdeas() const
{
    std::cout << "These are my " << this->getType() << " ideas: " << std::endl;
    this->_brain->printIdeas();
}