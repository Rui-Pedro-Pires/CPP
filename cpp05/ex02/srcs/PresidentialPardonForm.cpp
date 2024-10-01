/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiolive  <ruiolive@student.42.fr   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 10:29:56 by ruiolive          #+#    #+#             */
/*   Updated: 2024/10/01 11:23:35 by ruiolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("noname", "notarget", 0, 0)
{
}

PresidentialPardonForm::PresidentialPardonForm(const std::string target) : AForm("PresidentialPardonForm", target, 25, 5)
{
    std::cout << this->getName() << " created" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << this->getName() << " destroyed" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : AForm(other.getName(), other.getTarget(), other.getGradeToSign(), other.getGradeToExecute())
{
    std::cout << this->getName() << " copy created" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
    (void) other;
    return *this;    
}

void PresidentialPardonForm::action() const
{
    std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox." <<  std::endl;
}
