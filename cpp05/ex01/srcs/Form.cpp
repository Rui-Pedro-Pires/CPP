/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiolive  <ruiolive@student.42.fr   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 15:25:42 by ruiolive          #+#    #+#             */
/*   Updated: 2024/09/30 16:15:35 by ruiolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Form.hpp"

Form::Form() : _name("noname"), _gradeToSign(0), _gradeToExecute(0)
{
}

Form::Form(std::string name, const int gradeToSign, const int gradeToExecute) : _name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
    if (gradeToExecute < 1 || gradeToSign < 1)
        throw Form::GradeTooHighException();
    else if (gradeToExecute > 150 || gradeToSign > 150)
        throw Form::GradeTooLowException();
    this->_isSigned = false;
    std::cout << "Form " << this->_name << " created!" << std::endl;
}

Form::~Form()
{
    std::cout << "Form " << this->_name << " destroyed!" << std::endl;
}

Form::Form(const Form &other) : _name(other._name), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute) 
{
    this->_isSigned = other._isSigned;
}

Form &Form::operator=(const Form &other)
{
    if (this != &other)
        this->_isSigned = other._isSigned;
    return *this;
}

std::string Form::getName() const
{
    return this->_name;
}

int Form::getGradeToSign() const
{
    return this->_gradeToSign;
}

int Form::getGradeToExecute() const
{
    return this->_gradeToExecute;
}

bool Form::getIsSigned() const
{
    return this->_isSigned;
}

void    Form::beSigned(Bureaucrat& bureaucrat)
{
    if (bureaucrat.getgrade() > this->getGradeToSign())
        throw Form::GradeTooLowException();
    this->_isSigned = true;
}

const char* Form::GradeTooHighException::what() const throw()
{
    return "Grade too high!";
}

const char* Form::GradeTooLowException::what() const throw()
{
    return "Grade too low!";
}

std::ostream& operator<<(std::ostream& stream, const Form& form)
{
    stream << "Information about the form:" << "\n    Name: " << form.getName() << "\n    Grade to Sign: " << form.getGradeToSign() << "\n    Grade to Execute: " << form.getGradeToExecute() << "\n    Is Signed: " << form.getIsSigned();
    return stream;
}
