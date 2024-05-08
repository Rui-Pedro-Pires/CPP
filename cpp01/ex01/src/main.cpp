/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiolive <ruiolive@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 10:27:00 by ruiolive          #+#    #+#             */
/*   Updated: 2024/05/08 11:41:52 by ruiolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"

int main(void)
{
    Zombie  *arrayZombies;
    arrayZombies = zombieHorde(10, "ze");
    for (int i = 0; i < 10; i++) {
        arrayZombies[i].announce();
    }
    delete [] arrayZombies;
}
