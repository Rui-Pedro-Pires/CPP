/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiolive  <ruiolive@student.42.fr   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 10:27:00 by ruiolive          #+#    #+#             */
/*   Updated: 2024/05/08 10:28:31 by ruiolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"

Zombie::Zombie( void )
{
    this->_name = "Bino";
}

Zombie::Zombie( std::string name )
{
    this->_name = name;
}

Zombie::~Zombie()
{
    std::cout << this->_name << " <aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa" << std::endl;
}

void    Zombie::announce( void )
{
    std::cout << this->_name << ":" << ">: BraiiiiiiinnnzzzZ..." << std::endl;
}