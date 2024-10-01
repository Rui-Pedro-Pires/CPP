/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiolive  <ruiolive@student.42.fr   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 12:21:31 by ruiolive          #+#    #+#             */
/*   Updated: 2024/10/01 12:21:31 by ruiolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef Intern_HPP
# define Intern_HPP

#include <iostream>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern {
private:
    AForm*  ShrubberyCreationFormCreate(std::string target);
    AForm*  RobotomyRequestFormCreate(std::string target);
    AForm*  PresidentialPardonFormCreate(std::string target);
public:
    Intern();
    ~Intern();
    Intern(const Intern& other);
    Intern& operator=(const Intern& other);
    AForm*  makeform(std::string name, std::string target);

    class NoFormException : public std::exception
    {
    public:
        const char *what() const throw();
    };
};

typedef AForm*(Intern::*FORMS)(std::string target);

#endif
