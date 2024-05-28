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

#include "../includes/DiamondTrap.hpp"

int main( void )
{
    DiamondTrap DiamondTrap1( "John" );
    DiamondTrap DiamondTrap2( "Mick" );
    DiamondTrap DiamondTrap3( "Bino" );

    DiamondTrap1.whoiam();
    DiamondTrap2.whoiam();
    DiamondTrap3.whoiam();
    /*  DiamondTrap1.attackTarget( DiamondTrap2 );
     DiamondTrap2.attackTarget( DiamondTrap3 );
     DiamondTrap2.setAttackDamage( 10 );
     DiamondTrap2.highFivesGuys();
     DiamondTrap1.whoiam();
     DiamondTrap2.attackTarget( DiamondTrap1 );
     DiamondTrap1.beRepaired( 10 ); */

    return ( 0 );
}