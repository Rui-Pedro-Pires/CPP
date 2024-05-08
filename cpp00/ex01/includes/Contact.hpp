/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiolive  <ruiolive@student.42.fr   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 10:27:00 by ruiolive          #+#    #+#             */
/*   Updated: 2024/05/08 10:27:00 by ruiolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP
#include <iostream>

class Contact
{
private:
	int     _phone_number;
	std::string	_first_name;
	std::string	_last_name;
	std::string	_nick_name;
	std::string	_darkest_secret;

public:
	std::string	get_first_name();
	std::string	get_last_name();
	std::string	get_nick_name();
	std::string	get_darkest_secret();
	int     	get_phone_number();
	void    	set_first_name(std::string first_name);
	void    	set_last_name(std::string last_name);
	void    	set_nick_name(std::string nick_name);
	void    	set_phone_number(int phone_number);
	void    	set_darkest_secret(std::string darkest_secret);
};

#endif