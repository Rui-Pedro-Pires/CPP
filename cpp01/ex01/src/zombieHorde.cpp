/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiolive <ruiolive@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 11:11:50 by ruiolive          #+#    #+#             */
/*   Updated: 2024/05/08 11:45:14 by ruiolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
    Zombie  *arrayZombies = new Zombie[N];
    for (int i = 0; i < N; i++) {
        arrayZombies[i] = Zombie(name);
    }
    return (arrayZombies);
}