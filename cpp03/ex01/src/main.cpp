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

#include "../includes/ScavTrap.hpp"

int main( void )
{
    ScavTrap ScavTrap1( "John" );
    ScavTrap ScavTrap2( "Mick" );
    ScavTrap ScavTrap3( "Bino" );

    ScavTrap1.setAttackDamage( 3 );
    ScavTrap1.attackTarget( ScavTrap2 );
    ScavTrap2.attackTarget( ScavTrap3 );
    ScavTrap2.guardGate();
    ScavTrap2.setAttackDamage( 10 );
    ScavTrap2.attackTarget( ScavTrap1 );
    ScavTrap1.beRepaired( 10 );

    return ( 0 );
}