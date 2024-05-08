/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiolive  <ruiolive@student.42.fr   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 10:27:00 by ruiolive          #+#    #+#             */
/*   Updated: 2024/05/08 10:27:00 by ruiolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Contact.hpp"

std::string Contact::get_first_name()
{
    return (_first_name);
}

std::string Contact::get_last_name()
{
    return (_last_name);
}

std::string Contact::get_nick_name()
{
    return (_nick_name);
}

std::string Contact::get_darkest_secret()
{
    return (_darkest_secret);
}

int Contact::get_phone_number()
{
    return (_phone_number);
}

void Contact::set_first_name(std::string firstname)
{
    _first_name = firstname;
}

void Contact::set_last_name(std::string last_name)
{
    _last_name = last_name;
}

void Contact::set_nick_name(std::string nick_name)
{
    _nick_name = nick_name;
}

void Contact::set_darkest_secret(std::string darkest_secret)
{
    _darkest_secret = darkest_secret;
}

void Contact::set_phone_number(int phone_number)
{
    _phone_number = phone_number;
}
