/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiolive  <ruiolive@student.42.fr   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 10:23:27 by ruiolive          #+#    #+#             */
/*   Updated: 2024/10/01 10:23:45 by ruiolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("noname", "notarget", 0, 0)
{
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", target, 72, 45)
{
    std::cout << this->getName() << " created" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << this->getName() << " destroyed" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm(other.getName(), other.getTarget(), other.getGradeToSign(), other.getGradeToExecute())
{
    std::cout << this->getName() << " copy created" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
    if (this != &other)
        *this = other;
    return *this;
}

void RobotomyRequestForm::action() const
{
    srand(time(0));
    int randomNum = rand() % 2;
    if (randomNum)
    {
        std::cout << "!!DRILLINGZZZZZZZZZZZZ!!" << std::endl;
        std::cout <<  this->getTarget() <<" has been robotomized successfully" << std::endl;
    }
    else
        std::cout << "The robotomy failed" << std::endl;
}
