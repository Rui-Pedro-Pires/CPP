/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiolive <ruiolive@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 10:27:00 by ruiolive          #+#    #+#             */
/*   Updated: 2024/05/08 14:25:47 by ruiolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"

Zombie::Zombie( void )
{
}

Zombie::Zombie( std::string name )
{
    this->_name = name;
}

Zombie::~Zombie()
{
    std::cout << this->_name << ": raaaataaaa, ratttttttatatatata, raaaaaaaaaatatatatatata" << std::endl;
}

void    Zombie::announce( void )
{
    std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void    Zombie::setName( std::string name )
{
    this->_name = name;
}