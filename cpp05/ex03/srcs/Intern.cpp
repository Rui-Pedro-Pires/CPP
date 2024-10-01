/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiolive  <ruiolive@student.42.fr   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 12:21:37 by ruiolive          #+#    #+#             */
/*   Updated: 2024/10/01 12:21:37 by ruiolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Intern.hpp"

Intern::Intern() {}

Intern::~Intern() {}

Intern::Intern(const Intern& other) {
    (void) other;
}

Intern& Intern::operator=(const Intern& other) {
    (void) other;
    return *this;
}

AForm* Intern::makeform(std::string name, std::string target)
{
    AForm* formMenu[] = {
        new ShrubberyCreationForm(target),
        new RobotomyRequestForm(target),
        new PresidentialPardonForm(target),
    };

    std::string actionsMenu[] = {
        "ShrubberyCreationForm",
        "RobotomyRequestForm",
        "PresidentialPardonForm"
    };

    for (int i = 0; i < 3; ++i) {
        if (actionsMenu[i] == name)
        {
            std::cout << "Intern creates " << name << std::endl;
            return formMenu[i];
        }
    }
    throw NoFormException();
    return (NULL);
}

const char* Intern::NoFormException::what() const throw()
{
    return "No form with this name founded!";
}
