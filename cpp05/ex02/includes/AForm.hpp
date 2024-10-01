/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiolive  <ruiolive@student.42.fr   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 09:29:58 by ruiolive          #+#    #+#             */
/*   Updated: 2024/10/01 11:23:12 by ruiolive         ###   ########.fr       */
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

private:
  AForm();

public:
  AForm(const std::string name, const std::string target, const int gradeToSign, int gradeToExecute);
  virtual ~AForm();
  AForm(const AForm &other);
  AForm &operator=(const AForm &other);
  
  std::string getName() const;
  std::string getTarget() const;
  int getGradeToSign() const;
  int getGradeToExecute() const;
  bool getIsSigned() const;
  
  void beSigned(Bureaucrat const &bureaucrat);
  virtual void action() const = 0;
  void execute(Bureaucrat const & executor) const;

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
};

std::ostream &operator<<(std::ostream &stream, const AForm &form);

#endif
