/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiolive  <ruiolive@student.42.fr   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 13:36:46 by ruiolive          #+#    #+#             */
/*   Updated: 2024/06/03 13:36:46 by ruiolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Brain.hpp"

Brain::Brain()
{
    std::cout << "Brain started!" << std::endl;
    this->_ideas = new std::string[100];
    this->ideaNumber = 0;
}

Brain::~Brain()
{
    std::cout << "Brain stopped!" << std::endl;
    delete[] this->_ideas;
}

Brain::Brain( const Brain& other ): _ideas(new std::string[100])
{
    std::copy( other._ideas, other._ideas + 100, this->_ideas );
}

Brain& Brain::operator=( const Brain& other )
{
    if ( this != &other )
    {
        std::copy( other._ideas, other._ideas + 100, this->_ideas );
    }
    return *this;
}

void Brain::createIdea( std::string idea )
{
    if ( this->ideaNumber < 100 )
    {
        this->_ideas[ideaNumber] = idea;
        this->ideaNumber++;
    }
    else
    {
        std::cout << "I'm to old for this!" << std::endl;
    }
}

void Brain::printIdeas() const
{
    for ( int i = 0; i < 100; i++ ) {
        if (this->_ideas[i].empty())
            return;
        std::cout << this->_ideas[i] << std::endl;
    }
}