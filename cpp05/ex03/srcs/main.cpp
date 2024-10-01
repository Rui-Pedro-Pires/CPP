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

int main() {
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