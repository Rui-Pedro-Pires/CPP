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

#include "../includes/DiamondTrap.hpp"

int main( void )
{
    system( "clear" );
    DiamondTrap DiamondTrap1( "John" );
    DiamondTrap DiamondTrap2( "Mick" );

    sleep( 2 );
    DiamondTrap1.whoiam();
    DiamondTrap2.whoiam();
    sleep( 2 );
    DiamondTrap2.guardGate();
    sleep( 2 );
    DiamondTrap1.attackTarget( DiamondTrap2 );
    sleep( 2 );
    DiamondTrap2.highFivesGuys();
    sleep( 2 );
    DiamondTrap2.attackTarget( DiamondTrap1 );
    sleep( 2 );
    DiamondTrap1.beRepaired( 10 );
    sleep( 2 );
    std::cout << "End of game!!!!" << std::endl;

    return ( 0 );
}