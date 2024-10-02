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

bool ft_isdigit(std::string str)
{
	std::string::iterator itr;
	for (itr = str.begin(); itr < str.end(); itr++)
	{
		if (!isdigit(*itr))
			return (false);
	}
	return (true);
}

ScalarConverter::ScalarConverter() {}

ScalarConverter::~ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &other) { (void)other; }

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
	if (this != &other)
		return *this;
	return *this;
}

void ScalarConverter::convert(std::string &str)
{
	float str_float;
	double str_double;
	int str_int;
	char str_char;

	if (str.size() == 1 && !ft_isdigit(str))
	{
		sscanf(str.c_str(), "%c", &str_char);
		str_int = static_cast<int>(str_char);
		str_float = static_cast<float>(str_char);
		str_double = static_cast<double>(str_char);
	}
	else if (ft_isdigit(str))
	{
		sscanf(str.c_str(), "%d", &str_int);
		str_char = static_cast<char>(str_int);
		str_float = static_cast<float>(str_int);
		str_double = static_cast<double>(str_int);
	}
	else if (1)
	{
		sscanf(str.c_str(), "%f", &str_float);
		str_int = static_cast<int>(str_float);
		str_char = static_cast<char>(str_int);
		str_double = static_cast<double>(str_float);
	}
	else if (1)
	{
		sscanf(str.c_str(), "%lf", &str_double);
		str_int = static_cast<int>(str_double);
		str_char = static_cast<char>(str_int);
		str_float = static_cast<float>(str_double);
	}
	if (str_char > 32)
		std::cout << "char: " << str_char << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	std::cout << "int: " << str_int << std::endl;
	std::cout << "float: " << str_float << "f" << std::endl;
	std::cout << "double: " << str_double << std::endl;
}
