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

#include "../includes/FragTrap.hpp"

int main( void )
{
    FragTrap FragTrap1( "John" );
    FragTrap FragTrap2( "Mick" );
    FragTrap FragTrap3( "Bino" );

    FragTrap1.setAttackDamage( 3 );
    FragTrap1.attackTarget( FragTrap2 );
    FragTrap2.attackTarget( FragTrap3 );
    FragTrap2.setAttackDamage( 10 );
    FragTrap2.highFivesGuys();
    FragTrap2.attackTarget( FragTrap1 );
    FragTrap1.beRepaired( 10 );

    return ( 0 );
}