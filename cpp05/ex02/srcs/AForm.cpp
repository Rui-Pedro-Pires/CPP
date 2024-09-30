/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiolive  <ruiolive@student.42.fr   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by ruiolive          #+#    #+#             */
/*   Updated: 2024/09/30 20:05:02 by ruiolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AForm.hpp"

AForm::AForm() : _name("noname"), _gradeToSign(1), _gradeToExecute(1) {}

AForm::AForm(std::string name, std::string target, const int gradeToSign, const int gradeToExecute)
    : _name(name), _target(target), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
  if ((gradeToExecute < 1) != (gradeToSign < 1))
    throw AForm::GradeTooHighException();
  else if ((gradeToExecute > 150) != (gradeToSign > 150))
    throw AForm::GradeTooLowException();
  this->_isSigned = false;
}

AForm::~AForm() {}

AForm::AForm(const AForm &other)
    : _name(other._name), _target(other._target), _gradeToSign(other._gradeToSign),
      _gradeToExecute(other._gradeToExecute) {
  this->_isSigned = other._isSigned;
}

AForm &AForm::operator=(const AForm &other) {
  if (this != &other)
    this->_isSigned = other._isSigned;
  return *this;
}

std::string AForm::getName() const { return this->_name; }

std::string AForm::getTarget() const { return this->_target; }

int AForm::getGradeToSign() const { return this->_gradeToSign; }

int AForm::getGradeToExecute() const { return this->_gradeToExecute; }

bool AForm::getIsSigned() const { return this->_isSigned; }

void AForm::beSigned(Bureaucrat const &bureaucrat) {
  if (bureaucrat.getgrade() > this->getGradeToSign())
    throw AForm::GradeTooLowException();
  this->_isSigned = true;
}

const char *AForm::GradeTooHighException::what() const throw() {
  return "Grade too high!";
}

const char *AForm::GradeTooLowException::what() const throw() {
  return "Grade too low!";
}

std::ostream &operator<<(std::ostream &stream, const AForm &form) {
  stream << "Information about the form: " << form.getName() << "\n - "
         << form.getGradeToSign() << "\n - " << form.getGradeToExecute()
         << "\n - " << form.getIsSigned();
  return stream;
}
