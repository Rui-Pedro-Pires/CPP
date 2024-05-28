/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiolive  <ruiolive@student.42.fr   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 14:04:17 by ruiolive          #+#    #+#             */
/*   Updated: 2024/05/23 14:06:55 by ruiolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

#include "../includes/ScavTrap.hpp"

int main( void )
{
    system( "clear" );
    ScavTrap ScavTrap1( "John" );
    ScavTrap ScavTrap2( "Mick" );

    sleep( 2 );
    ScavTrap1.attackTarget( ScavTrap2 );
    sleep( 2 );
    ScavTrap2.guardGate();
    sleep( 2 );
    ScavTrap2.attackTarget( ScavTrap1 );
    sleep( 2 );
    ScavTrap1.beRepaired( 10 );
    sleep( 2 );
    std::cout << "End of game!!!!" << std::endl;

    return ( 0 );
}