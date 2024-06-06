/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiolive  <ruiolive@student.42.fr   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 11:20:05 by ruiolive          #+#    #+#             */
/*   Updated: 2024/06/03 11:20:05 by ruiolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Animal.hpp"
#include "../includes/Cat.hpp"
#include "../includes/Dog.hpp"

int main()
{
    Dog dog;
    Dog dog1;
    Cat cat;
    Animal* animals[] = { new Dog(), new Dog( dog ), new Cat(), new Cat( cat ) };

    for ( int i = 0; i < 4; i++ )
    {
        delete animals[i];
    }
    std::cout << "----------------" << std::endl;
    dog = dog1;
    return 0;
}