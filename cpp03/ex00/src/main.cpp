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

int main(void)
{
    ClapTrap clapTrap1("John");
    ClapTrap clapTrap2("Mick");
    ClapTrap clapTrap3("Bino");

    system("clear");
    clapTrap1.setAttackDamage(3);
    system("sleep 1");
    clapTrap1.attackTarget(clapTrap2);
    system("sleep 2");
    clapTrap2.attackTarget(clapTrap3);
    system("sleep 2");
    clapTrap2.setAttackDamage(10);
    system("sleep 1");
    clapTrap2.attackTarget(clapTrap1);
    system("sleep 2");
    clapTrap2.attackTarget(clapTrap1);
    system("sleep 2");
    clapTrap1.beRepaired(10);
    system("sleep 1");
    clapTrap1.attackTarget(clapTrap2);
    system("sleep 2");
    clapTrap1.attackTarget(clapTrap2);
    system("sleep 2");
    clapTrap1.attackTarget(clapTrap2);
    system("sleep 2");
    clapTrap1.attackTarget(clapTrap2);
    system("sleep 2");
    clapTrap1.attackTarget(clapTrap2);
    system("sleep 2");
    clapTrap1.attackTarget(clapTrap2);
    system("sleep 2");
    clapTrap1.attackTarget(clapTrap2);
    system("sleep 2");
    clapTrap1.attackTarget(clapTrap2);
    system("sleep 2");
    clapTrap1.attackTarget(clapTrap2);
    system("sleep 2");
    clapTrap1.attackTarget(clapTrap2);
    system("sleep 2");
    clapTrap1.attackTarget(clapTrap2);

    std::cout << "End of game!!!!" << std::endl;
    std::cin.get();
    
    return (0);
}