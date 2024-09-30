/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiolive  <ruiolive@student.42.fr   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by ruiolive          #+#    #+#             */
/*   Updated: 2024/09/30 20:56:01 by ruiolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", target, 145, 137)
{
    std::cout << this->getName() << " created" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << this->getName() << " destroyed" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other.getName(), other.getTarget(), other.getGradeToSign(), other.getGradeToExecute())
{
    std::cout << this->getName() << " copy created" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
    (void) other;
    return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor)
{
    try {
        this->beSigned(executor);
        std::cout << executor.getname() << " signed " << this->getName() << std::endl;
        std::string filename = executor.getname() + "_shrubbery";
        std::ofstream filestream(filename.c_str());
        std::cout << filename << " created" << std::endl;
        filestream << "hello gato" << std::endl;
    } catch (const std::exception &e) {
        std::cerr << executor.getname() << " couldn’t sign " << this->getName()
                << " because " << e.what() << std::endl;
    }
}