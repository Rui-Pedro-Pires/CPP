/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiolive  <ruiolive@student.42.fr   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 09:29:58 by ruiolive          #+#    #+#             */
/*   Updated: 2024/10/01 11:35:11 by ruiolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AForm.hpp"

AForm::AForm() : _name("noname"), _gradeToSign(0), _gradeToExecute(0) {}

AForm::AForm(std::string name, std::string target, const int gradeToSign, const int gradeToExecute)
    : _name(name), _target(target), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
  if (gradeToExecute < 1 || gradeToSign < 1)
    throw AForm::GradeTooHighException();
  else if (gradeToExecute > 150 || gradeToSign > 150)
    throw AForm::GradeTooLowException();
  this->_isSigned = false;
  std::cout << "Form " << this->_name << " created!" << std::endl;
}

AForm::~AForm()
{
  std::cout << "Form " << this->_name << " destroyed!" << std::endl;
}

AForm::AForm(const AForm &other)
    : _name(other._name), _target(other._target), _gradeToSign(other._gradeToSign),
      _gradeToExecute(other._gradeToExecute)
{
  this->_isSigned = other._isSigned;
}

AForm &AForm::operator=(const AForm &other)
{
  if (this != &other)
    this->_isSigned = other._isSigned;
  return *this;
}

std::string AForm::getName() const { return this->_name; }

std::string AForm::getTarget() const { return this->_target; }

int AForm::getGradeToSign() const { return this->_gradeToSign; }

int AForm::getGradeToExecute() const { return this->_gradeToExecute; }

bool AForm::getIsSigned() const { return this->_isSigned; }

void AForm::beSigned(Bureaucrat const &bureaucrat)
{
  if (bureaucrat.getgrade() > this->getGradeToSign())
    throw AForm::GradeTooLowException();
  this->_isSigned = true;
}

void AForm::execute(Bureaucrat const &bureaucrat) const
{
  if (this->_isSigned == false)
    throw NotSignedException();
  else if (bureaucrat.getgrade() > this->getGradeToExecute())
    throw GradeTooLowException();
}

const char *AForm::GradeTooHighException::what() const throw()
{
  return "grade is too high!";
}

const char *AForm::GradeTooLowException::what() const throw()
{
  return "grade is too low!";
}

const char *AForm::NotSignedException::what() const throw()
{
  return "form is not signed!";
}

std::ostream &operator<<(std::ostream &stream, const AForm &form)
{
  stream << "Information about the form: " << form.getName() << "\n - "
         << form.getGradeToSign() << "\n - " << form.getGradeToExecute()
         << "\n - " << form.getIsSigned();
  return stream;
}
