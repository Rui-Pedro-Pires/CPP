/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiolive  <ruiolive@student.42.fr   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 15:59:21 by ruiolive          #+#    #+#             */
/*   Updated: 2024/06/05 15:59:21 by ruiolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AMateria.hpp"
#include "../includes/Character.hpp"
#include "../includes/Cure.hpp"
#include "../includes/Ice.hpp"
#include "../includes/MateriaSource.hpp"

int main( void )
{
    IMateriaSource* src = new MateriaSource();
    src->learnMateria( new Ice() );
    src->learnMateria( new Cure() );
    ICharacter* me = new Character( "me" );
    AMateria* tmp;
    tmp = src->createMateria( "ice" );
    me->equip( tmp );
    tmp = src->createMateria( "cure" );
    me->equip( tmp );
    ICharacter* bob = new Character( "bob" );
    me->use( 0, *bob );
    me->use( 1, *bob );
    me->unequip(1);

    Character ze( "ze" );
    Character bino( "bino");

    ze.equip(src->createMateria("ice"));
    ze.equip(src->createMateria("cure"));

    bino = ze;
    bino.use(0, *bob);
    bino.use(1, *bob);
    bino.unequip(0);
    bino.use(0, *bob);
    bino.unequip(1);
    bino.equip(src->createMateria("cure"));
    bino.equip(src->createMateria("cure"));
    bino.equip(src->createMateria("cure"));
    bino.unequip(0);
    bino.unequip(1);
    bino.unequip(2);
    

    delete bob;
    delete me;
    delete src;
    return ( 0 );
}