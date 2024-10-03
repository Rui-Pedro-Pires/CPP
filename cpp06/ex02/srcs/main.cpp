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
void identify(Base *p);
void identify(Base &p);

int main(void)
{
    Base *base;

    base = generate();
    identify(base);
    identify(*base);
}

Base *generate(void)
{
    Base *base;
    int randomnum;

    srand(time(0));
    randomnum = rand() % 3;
    if (randomnum == 0)
        base = new A;
    else if (randomnum == 1)
        base = new B;
    else if (randomnum == 2)
        base = new C;
    else
        base = NULL;
    return base;
}

void identify(Base *p)
{
    if (dynamic_cast<A *>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B *>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C *>(p))
        std::cout << "C" << std::endl;
    else
        std::cout << "No type found!" << std::endl;
}

void identify(Base &p)
{
    if (dynamic_cast<A *>(&p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B *>(&p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C *>(&p))
        std::cout << "C" << std::endl;
    else
        std::cout << "No type found!" << std::endl;
}