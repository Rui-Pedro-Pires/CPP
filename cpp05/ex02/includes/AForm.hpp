/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiolive  <ruiolive@student.42.fr   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by ruiolive          #+#    #+#             */
/*   Updated: 2024/09/30 20:52:05 by ruiolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef Form_HPP
#define Form_HPP

#include "Bureaucrat.hpp"
#include <iostream>


class Bureaucrat;

class AForm {
private:
  const std::string _name;
  const std::string _target;
  bool _isSigned;
  const int _gradeToSign;
  const int _gradeToExecute;

public:
  AForm(const std::string name, const std::string target, const int gradeToSign, int gradeToExecute);
  ~AForm();
  AForm(const AForm &other);
  AForm &operator=(const AForm &other);
  std::string getName() const;
  std::string getTarget() const;
  int getGradeToSign() const;
  int getGradeToExecute() const;
  bool getIsSigned() const;
  void beSigned(Bureaucrat const &bureaucrat);
  virtual void execute(Bureaucrat const & executor) const = 0;
  class GradeTooHighException : public std::exception {
  public:
    const char *what() const throw();
  };
  class GradeTooLowException : public std::exception {
  public:
    const char *what() const throw();
  };
  class NotSignedException : public std::exception {
  public:
    const char *what() const throw();
  };
private:
  AForm();
};

std::ostream &operator<<(std::ostream &stream, const AForm &form);

#endif
