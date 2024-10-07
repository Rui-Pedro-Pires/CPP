
#pragma once
#ifndef Bureaucrat_HPP
#define Bureaucrat_HPP

#include "AForm.hpp"
#include <iostream>

class AForm;

class Bureaucrat {
private:
  std::string _name;
  int _grade;

private:
  Bureaucrat();

public:
  Bureaucrat(std::string _name, int grade);
  ~Bureaucrat();
  Bureaucrat(const Bureaucrat &other);
  Bureaucrat &operator=(const Bureaucrat &other);

  std::string getname() const;
  int getgrade() const;

  void incrementgrade();
  void decrementgrade();
  void signForm(AForm & form);
  void executeForm(AForm const & form);

  class GradeTooHighException : public std::exception {
  public:
    const char *what() const throw();
  };
  class GradeTooLowException : public std::exception {
  public:
    const char *what() const throw();
  };
};

std::ostream &operator<<(std::ostream &stream, const Bureaucrat &Bureaucrat);

#endif
