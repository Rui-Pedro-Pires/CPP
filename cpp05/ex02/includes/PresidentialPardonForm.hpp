/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiolive  <ruiolive@student.42.fr   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 10:29:49 by ruiolive          #+#    #+#             */
/*   Updated: 2024/10/01 11:22:57 by ruiolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef PresidentialPardonForm_HPP
# define PresidentialPardonForm_HPP

# include "AForm.hpp"
# include <iostream>

class PresidentialPardonForm : public AForm
{
private:
    PresidentialPardonForm();

public:
    PresidentialPardonForm(std::string target);
    ~PresidentialPardonForm();
    PresidentialPardonForm(const PresidentialPardonForm& other);
    PresidentialPardonForm& operator=(const PresidentialPardonForm& other);

    void action() const;
};

#endif
