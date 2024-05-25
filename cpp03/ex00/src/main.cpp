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

int main(void)
{
    ClapTrap clapTrap1("John");
    ClapTrap clapTrap2("Mick");
    ClapTrap clapTrap3("Bino");

    clapTrap1.setAttackDamage(3);
    clapTrap1.attackTarget(clapTrap2);
    clapTrap2.attackTarget(clapTrap3);
    clapTrap2.setAttackDamage(10);
    clapTrap2.attackTarget(clapTrap1);
    clapTrap1.beRepaired(10);
    
    return (0);
}