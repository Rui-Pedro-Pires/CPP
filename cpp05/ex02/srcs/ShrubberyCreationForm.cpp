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

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("noname", "notarget", 0, 0)
{
}

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

void ShrubberyCreationForm::action() const
{
  std::string filename = this->getTarget() + "_shrubbery";
  std::ofstream outfile(filename.c_str());
  outfile << "\
              v .   ._, |_  .,\n\
             `-._\\/  .  \\ /    |/_\n\
               \\  _\\, y | \\//\n\
         _\\_.___\\, \\/ -.\\||\n\
           `7-,--.`._||  / / ,\n\
           /'     `-. `./ / |/_.'\n\
                     |    |//\n\
                     |_    /\n\
                     |-   |\n\
                     |   =|\n\
                     |    |\n\
--------------------/ ,  . \\--------._" << std::endl;
}