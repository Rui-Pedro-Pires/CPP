/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiolive  <ruiolive@student.42.fr   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by ruiolive          #+#    #+#             */
/*   Updated: 2024/09/30 20:04:13 by ruiolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"

Bureaucrat::Bureaucrat() {}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name) {
  if (grade > 150)
    throw Bureaucrat::GradeTooLowException();
  else if (grade < 1)
    throw Bureaucrat::GradeTooHighException();
  this->_grade = grade;
  std::cout << "Bureaucrat " << this->_name << " created!" << std::endl;
}

Bureaucrat::~Bureaucrat() {
  std::cout << "Bureaucrat " << this->_name << " Destroyed!" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other)
    : _name(other._name), _grade(other._grade) {}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other) {
  if (this != &other) {
    this->_grade = other._grade;
  }
  return *this;
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
  return "Grade too high!";
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
  return "Grade too low!";
}

std::string Bureaucrat::getname() const { return this->_name; }

int Bureaucrat::getgrade() const { return this->_grade; }

void Bureaucrat::incrementgrade() {
  if (this->_grade == 1)
    throw Bureaucrat::GradeTooHighException();
  this->_grade--;
}

void Bureaucrat::decrementgrade() {
  if (this->_grade == 150)
    throw Bureaucrat::GradeTooLowException();
  this->_grade++;
}

void Bureaucrat::executeForm(AForm const &form) {
  try {
    form.execute(*this);
  } catch (const std::exception &e) {
    std::cerr << e.what() << '\n';
  }
}

std::ostream &operator<<(std::ostream &stream, const Bureaucrat &Bureaucrat) {
  stream << Bureaucrat.getname() << ", bureaucrat grade "
         << Bureaucrat.getgrade();
  return stream;
}
