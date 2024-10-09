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
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    std::cout << mstack.top() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }

    ////////// MY TESTS //////////
    MutantStack<int, std::vector<int> > mstackVec1;
    mstackVec1.push(50);
    mstackVec1.push(10);
    MutantStack<int, std::vector<int> > mstackVec2(mstackVec1);
    mstackVec2.pop();
    mstackVec2.push(200);
    mstackVec2.push(234);
    std::cout << "-------MstackVec1-------" << std::endl;
    MutantStack<int, std::vector<int> >::iterator it1 = mstackVec1.begin();
    MutantStack<int, std::vector<int> >::iterator ite1 = mstackVec1.end();
    while (it1 != ite1)
    {
        std::cout << *it1 << std::endl;
        ++it1;
    }
    std::cout << "-------MstackVec2-------" << std::endl;
    MutantStack<int, std::vector<int> >::const_iterator it2 = mstackVec2.cbegin();
    MutantStack<int, std::vector<int> >::const_iterator ite2 = mstackVec2.cend();
    while (it2 != ite2)
    {
        std::cout << *it2 << std::endl;
        ++it2;
    }
    std::cout << "-------Mstack3-------" << std::endl;
    MutantStack<int> mstack3;
    mstack3.push(200);
    mstack3.push(234);
    MutantStack<int>::reverse_iterator it3 = mstack3.rbegin();
    MutantStack<int>::reverse_iterator ite3 = mstack3.rend();
    while (it3 != ite3)
    {
        std::cout << *it3 << std::endl;
        ++it3;
    }
    std::cout << "-------str_Stack-------" << std::endl;
    MutantStack<std::string, std::list<std::string> > str_Stack;
    str_Stack.push("cao");
    str_Stack.push("e");
    str_Stack.push("gato");
    MutantStack<std::string, std::list<std::string> >::const_reverse_iterator it4 = str_Stack.crbegin();
    MutantStack<std::string, std::list<std::string> >::const_reverse_iterator ite4 = str_Stack.crend();
    while (it4 != ite4)
    {
        std::cout << *it4 << std::endl;
        ++it4;
    }
    return 0;
}