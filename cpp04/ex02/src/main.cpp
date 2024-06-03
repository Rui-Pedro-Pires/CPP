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
    Cat cat;
    Animal* animals[] = { new Dog(), new Dog( dog ), new Cat(), new Cat( cat ) };

    animals[0]->addIdea("eu sou um cao");
    animals[0]->addIdea("e sou lindo");
    animals[0]->printIdeas();
    animals[2]->addIdea("eu sou um gato");
    animals[2]->addIdea("e sou lindo");
    animals[2]->printIdeas();
    for ( int i = 0; i < 4; i++ )
    {
        delete animals[i];
    }
    return 0;
}