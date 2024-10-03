/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiolive  <ruiolive@student.42.fr   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 16:21:57 by ruiolive          #+#    #+#             */
/*   Updated: 2024/10/03 16:21:57 by ruiolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Base.hpp"
#include "../includes/A.hpp"
#include "../includes/B.hpp"
#include "../includes/C.hpp"

Base *generate(void);

int main(void)
{
    Base *base;

    base = generate();
}

Base *generate(void)
{
    Base *base;
    int randomnum;

    srand(time(0));
    randomnum = rand() % 3;
    switch (randomnum)
    {
    case 1:
        base = new A;
        break;
    case 2:
        base = new B;
        break;
    case 3:
        base = new C;
        break;
    default:
        break;
    }
    return base;
}

void identify(Base *p)
{
    if (dynamic_cast<A *>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<A *>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<A *>(p))
        std::cout << "A" << std::endl;
}

void identify(Base &p)
{
    if (dynamic_cast<A *>(&p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<A *>(&p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<A *>(&p))
        std::cout << "A" << std::endl;
}