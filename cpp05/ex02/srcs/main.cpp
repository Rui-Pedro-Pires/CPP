/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiolive  <ruiolive@student.42.fr   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 19:39:57 by ruiolive          #+#    #+#             */
/*   Updated: 2024/10/07 21:31:56 by ruiolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/Bureaucrat.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"

int main()
{
  try
  {
    Bureaucrat ze("ze", 70);
    ShrubberyCreationForm f1("manuel");
    RobotomyRequestForm f2("miguel");
    PresidentialPardonForm f3("zezinho");

    ze.signForm(f1);
    ze.signForm(f2);
    ze.signForm(f3);
    ze.executeForm(f1);
    ze.executeForm(f2);
    ze.executeForm(f3);
  }
  catch (const std::exception &e)
  {
    std::cerr << e.what() << '\n';
  }
}