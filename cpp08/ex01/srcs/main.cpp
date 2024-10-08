/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiolive  <ruiolive@student.42.fr   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 12:16:45 by ruiolive          #+#    #+#             */
/*   Updated: 2024/10/07 12:16:45 by ruiolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Span.hpp"

int main(int, char **)
{
    srand(time(0));
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;

    std::cout << "------My Tests-------" << std::endl;
    std::vector<int> vec;
    for (int i = 0; i < 10000; i++)
    {
        vec.push_back(rand() % 10000);
    }
    std::cout << "First Test:" << std::endl;
    try
    {
        Span sp2 = Span(10000);
        sp2.addManyNumbers(vec);
        std::cout << sp2.shortestSpan() << std::endl;
        std::cout << sp2.longestSpan() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << "Second Test:" << std::endl;
    try
    {
        Span sp3 = Span(1);
        std::cout << sp3.shortestSpan() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << "Third Test:" << std::endl;
    try
    {
        Span sp4 = Span(1);
        sp4.addNumber(1);
        sp4.addNumber(2);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    return 0;
}