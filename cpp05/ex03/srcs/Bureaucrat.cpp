/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiolive  <ruiolive@student.42.fr   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 19:39:57 by ruiolive          #+#    #+#             */
/*   Updated: 2024/10/07 21:32:06 by ruiolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/Bureaucrat.hpp"

Bureaucrat::Bureaucrat() {}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
  if (grade > 150)
    throw Bureaucrat::GradeTooLowException();
  else if (grade < 1)
    throw Bureaucrat::GradeTooHighException();
  this->_grade = grade;
  std::cout << "Bureaucrat " << this->_name << " created!" << std::endl;
}

Bureaucrat::~Bureaucrat()
{
  std::cout << "Bureaucrat " << this->_name << " Destroyed!" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other)
    : _name(other._name), _grade(other._grade) {}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
  if (this != &other)
  {
    this->_grade = other._grade;
  }
  return *this;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
  return "grade too high!";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
  return "grade too low!";
}

std::string Bureaucrat::getname() const { return this->_name; }

int Bureaucrat::getgrade() const { return this->_grade; }

void Bureaucrat::incrementgrade()
{
  if (this->_grade == 1)
    throw Bureaucrat::GradeTooHighException();
  this->_grade--;
}

void Bureaucrat::decrementgrade()
{
  if (this->_grade == 150)
    throw Bureaucrat::GradeTooLowException();
  this->_grade++;
}

void Bureaucrat::signForm(AForm &form)
{
  try
  {
    form.beSigned(*this);
    std::cout << this->getname() << " signed " << form.getName() << std::endl;
  }
  catch (const std::exception &e)
  {
    std::cerr << this->getname() << " couldn’t sign " << form.getName() << " because " << e.what() << std::endl;
  }
}

void Bureaucrat::executeForm(AForm const &form)
{
  try
  {
    form.execute(*this);
    std::cout << this->getname() << " executed " << form.getName() << std::endl;
  }
  catch (std::exception &e)
  {
    std::cerr << this->getname() << " couldn’t execute " << form.getName() << " because " << e.what() << std::endl;
  }
}

std::ostream &operator<<(std::ostream &stream, const Bureaucrat &Bureaucrat)
{
  stream << Bureaucrat.getname() << ", bureaucrat grade "
         << Bureaucrat.getgrade();
  return stream;
}
