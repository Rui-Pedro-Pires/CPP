/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiolive  <ruiolive@student.42.fr   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 12:16:46 by ruiolive          #+#    #+#             */
/*   Updated: 2024/10/07 12:16:46 by ruiolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/MutantStack.hpp"

int main()
{
    std::cout << "-------Mstack-------" << std::endl;
    MutantStack<int, std::vector<int> > mstack;
    mstack.push( 5 );
    mstack.push( 17 );
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    std::cout << mstack.top() << std::endl;
    mstack.push( 3 );
    mstack.push( 5 );
    mstack.push( 737 );
    mstack.push( 0 );
    MutantStack<int, std::vector<int> >::iterator it = mstack.begin();
    MutantStack<int, std::vector<int> >::iterator ite = mstack.end();
    ++it;
    --it;
    std::cout << std::endl;
    while ( it != ite )
    {
        std::cout << *it << std::endl;
        ++it;
    }

    ////////// MY TESTS //////////
    MutantStack<int, std::vector<int> > mstack1 = mstack;
    MutantStack<int, std::vector<int> > mstack2( mstack1 );
    mstack2.pop();
    mstack2.push( 200 );
    mstack2.push( 234 );
    std::cout << "-------Mstack1-------" << std::endl;
    MutantStack<int, std::vector<int> >::iterator it1 = mstack1.begin();
    MutantStack<int, std::vector<int> >::iterator ite1 = mstack1.end();
    while ( it1 != ite1 )
    {
        std::cout << *it1 << std::endl;
        ++it1;
    }
    std::cout << "-------Mstack2-------" << std::endl;
    MutantStack<int, std::vector<int> >::iterator it2 = mstack2.begin();
    MutantStack<int, std::vector<int> >::iterator ite2 = mstack2.end();
    while ( it2 != ite2 )
    {
        std::cout << *it2 << std::endl;
        ++it2;
    }
    std::cout << "-------str_Stack-------" << std::endl;
    MutantStack<std::string, std::list<std::string> > str_Stack;
    str_Stack.push( "cao" );
    str_Stack.push( "e" );
    str_Stack.push( "gato" );
    MutantStack<std::string, std::list<std::string> >::iterator it3 = str_Stack.begin();
    MutantStack<std::string, std::list<std::string> >::iterator ite3 = str_Stack.end();
    while ( it3 != ite3 )
    {
        std::cout << *it3 << std::endl;
        ++it3;
    }
    return 0;
}