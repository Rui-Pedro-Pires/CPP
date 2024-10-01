/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiolive  <ruiolive@student.42.fr   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 15:51:11 by ruiolive          #+#    #+#             */
/*   Updated: 2024/10/01 15:51:11 by ruiolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::~ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
	if (this != &other)

		return *this;
}

void ScalarConverter::convert(char *str)
{
	float str_float;
	double str_double;
	int	str_int;
	std::string temp;

	temp = str;
	str_int = std::stoi(temp);
	str_float = std::stof(temp);
	str_double = std::stod(temp);
	std::cout << "int: " << str_int << std::endl;
	std::cout << "float: " << str_float << std::endl;
	std::cout << "double: " << str_double << std::endl;
}
