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

#include "../includes/ClapTrap.hpp"
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    system("clear");
    ClapTrap clapTrap1("John");
    ClapTrap clapTrap2("Mick");

    sleep(2);
    clapTrap1.setAttackDamage(3);
    sleep(2);
    clapTrap1.attackTarget(clapTrap2);
    sleep(2);
    clapTrap2.setAttackDamage(10);
    sleep(2);
    clapTrap2.attackTarget(clapTrap1);
    sleep(2);
    clapTrap2.attackTarget(clapTrap1);
    sleep(2);
    clapTrap1.beRepaired(10);
    sleep(2);
    clapTrap1.attackTarget(clapTrap2);
    sleep(2);
    clapTrap1.attackTarget(clapTrap2);
    sleep(2);
    clapTrap1.attackTarget(clapTrap2);
    sleep(2);
    clapTrap1.attackTarget(clapTrap2);
    sleep(2);
    clapTrap1.attackTarget(clapTrap2);
    sleep(2);
    clapTrap1.attackTarget(clapTrap2);
    sleep(2);
    clapTrap1.attackTarget(clapTrap2);
    sleep(2);
    clapTrap1.attackTarget(clapTrap2);
    sleep(2);
    clapTrap1.attackTarget(clapTrap2);
    sleep(2);
    std::cout << "End of game!!!!" << std::endl;
    
    return (0);
}