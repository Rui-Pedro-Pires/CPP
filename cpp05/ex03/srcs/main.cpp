/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiolive  <ruiolive@student.42.fr   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 12:17:39 by ruiolive          #+#    #+#             */
/*   Updated: 2024/10/07 12:17:39 by ruiolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiolive  <ruiolive@student.42.fr   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 09:29:58 by ruiolive          #+#    #+#             */
/*   Updated: 2024/10/01 11:34:06 by ruiolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/Intern.hpp"

int main()
{
  AForm *pres;
  Intern zezita;
  ShrubberyCreationForm f1("manuel");
  RobotomyRequestForm f2("miguel");
  try
  {
    Bureaucrat ze("ze", 70);
    pres = zezita.makeform("PresidentialPardonForm", "manel");
    ze.signForm(*pres);
    ze.signForm(f1);
    ze.signForm(f2);
    ze.executeForm(*pres);
    ze.executeForm(f1);
    ze.executeForm(f2);
    delete pres;
  }
  catch (std::exception &e)
  {
    std::cerr << e.what() << std::endl;
  }
}