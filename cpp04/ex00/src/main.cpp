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
    Animal* animals[] = { new Dog(), new Cat(), new Animal() };

    for (int i = 0; i < 3; i++) {
        LOG(animals[i]->getType());
        animals[i]->makeSound();
        delete animals[i];
    }

    Dog dog1;
    Animal* dog2 = new Dog(dog1);

    LOG(dog2->getType());
    dog2->makeSound();
    delete dog2;
    return 0;
}