/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiolive  <ruiolive@student.42.fr   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 15:07:23 by ruiolive          #+#    #+#             */
/*   Updated: 2024/09/30 15:00:49 by ruiolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat ze("ze", 150);
        std::cout << ze << std::endl;
        ze.incrementGrade();
        std::cout << ze << std::endl;
        ze.decrementGrade();
        std::cout << ze << std::endl;
        ze.decrementGrade();
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        Bureaucrat manuel("manuel", 160);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        Bureaucrat miguel("miguel", 0);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}