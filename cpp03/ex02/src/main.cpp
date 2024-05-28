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

#include "../includes/FragTrap.hpp"

int main( void )
{
    system( "clear" );
    FragTrap FragTrap1( "John" );
    FragTrap FragTrap2( "Mick" );

    sleep( 2 );
    FragTrap1.attackTarget( FragTrap2 );
    sleep( 2 );
    FragTrap2.attackTarget( FragTrap1 );
    sleep( 2 );
    FragTrap2.highFivesGuys();
    sleep( 2 );
    FragTrap2.attackTarget( FragTrap1 );
    sleep( 2 );
    FragTrap1.beRepaired( 10 );
    sleep( 2 );
    std::cout << "End of game!!!!" << std::endl;

    return ( 0 );
}