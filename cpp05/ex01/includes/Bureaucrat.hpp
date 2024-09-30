/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiolive  <ruiolive@student.42.fr   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 15:25:00 by ruiolive          #+#    #+#             */
/*   Updated: 2024/09/30 16:22:09 by ruiolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef Bureaucrat_HPP
#define Bureaucrat_HPP

#include <iostream>
#include "Form.hpp"

class Form;

class Bureaucrat
{
private:
    std::string _name;
    int _grade;

public:
    Bureaucrat(std::string _name, int grade);
    ~Bureaucrat();
    Bureaucrat(const Bureaucrat &other);
    Bureaucrat &operator=(const Bureaucrat &other);
    void incrementgrade();
    void decrementgrade();
    std::string getname() const;
    int getgrade() const;
    void signForm(Form &form);
    class GradeTooHighException : public std::exception
    {
    public:
        const char *what() const throw();
    };
    class GradeTooLowException : public std::exception
    {
    public:
        const char *what() const throw();
    };

private:
    Bureaucrat();
};

std::ostream &operator<<(std::ostream &stream, const Bureaucrat &Bureaucrat);

#endif
