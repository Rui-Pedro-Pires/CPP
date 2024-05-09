/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiolive  <ruiolive@student.42.fr   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 19:49:34 by ruiolive          #+#    #+#             */
/*   Updated: 2024/05/09 19:49:34 by ruiolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"

int main(void)
{
    Zombie *bino2;
    
    Zombie bino1("animal");
    bino2 = newZombie("cao");
    if (!bino2)
        return (0);
    bino1.announce();
    bino2->announce();
    randomChump("galinha");
    delete bino2;
}
