#pragma once
#ifndef Bureaucrat_HPP
#define Bureaucrat_HPP

#include <iostream>

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
