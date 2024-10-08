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
    MutantStack<int> mstack;
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
    std::cout << "-------Mstack-------" << std::endl;
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    std::cout << std::endl;
    while ( it != ite )
    {
        std::cout << *it << std::endl;
        ++it;
    }


    ////////// MY TESTS //////////
    MutantStack<int> mstack1 = mstack;
    MutantStack<int> mstack2(mstack1);
    mstack2.pop();
    mstack2.push(200);
    mstack2.push(234);
    std::cout << "-------Mstack1-------" << std::endl;
    MutantStack<int>::iterator it1 = mstack1.begin();
    MutantStack<int>::iterator ite1 = mstack1.end();
     while ( it1 != ite1 )
    {
        std::cout << *it1 << std::endl;
        ++it1;
    }
    std::cout << "-------Mstack2-------" << std::endl;
    MutantStack<int>::iterator it2 = mstack2.begin();
    MutantStack<int>::iterator ite2 = mstack2.end();
    while ( it2 != ite2 )
    {
        std::cout << *it2 << std::endl;
        ++it2;
    }
    std::stack<int> s( mstack );
    return 0;
}