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
}

Brain::~Brain()
{
    std::cout << "Brain stopped!" << std::endl;
}

Brain::Brain( const Brain& other )
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
