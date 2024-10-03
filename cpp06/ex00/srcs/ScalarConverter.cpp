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
  long str_int;
  char str_char;
  errno = 0;

  if (str.size() == 1 && !ft_isdigit(str))
  {
    str_char = str[0];
    str_int = static_cast<int>(str_char);
    str_float = static_cast<float>(str_char);
    str_double = static_cast<double>(str_char);
  }
  else if (check_if_int(str))
  {
    str_int = strtol(str.c_str(), NULL, 10);
    str_char = static_cast<char>(str_int);
    str_float = static_cast<float>(str_int);
    str_double = static_cast<double>(str_int);
  }
  else if (float_or_double(str) == 1)
  {
    str_float = strtof(str.c_str(), NULL);
    str_int = static_cast<int>(str_float);
    str_char = static_cast<char>(str_int);
    str_double = static_cast<double>(str_float);
  }
  else if (float_or_double(str) == 2)
  {
    str_double = strtod(str.c_str(), NULL);
    str_int = static_cast<int>(str_double);
    str_char = static_cast<char>(str_int);
    str_float = static_cast<float>(str_double);
  }
  else
    return (error_information());
  if (errno == ERANGE || str_int > INT_MAX || str_int < INT_MIN)
    return (error_information());
  num_information(str_char, str_int, str_float, str_double);
}

void num_information(char str_char, long str_int, float str_float, double str_double)
{
  if (str_int < 32 && str_int > 0)
    std::cout << "char: Non displayable" << std::endl;
  else if (str_int < 0 || str_int > 126)
    std::cout << "char: impossible" << std::endl;
  else
    std::cout << "char: " << str_char << std::endl;
  std::cout << "int: " << str_int << std::endl;
  std::cout << std::fixed << std::setprecision(1) << "float: " << str_float << "f" << std::endl;
  std::cout << std::fixed << "double: " << str_double << std::endl;
}

void error_information(void)
{
  std::cout << "char: impossible" << std::endl;
  std::cout << "int: impossible" << std::endl;
  std::cout << "float: impossible" << std::endl;
  std::cout << "double: impossible" << std::endl;
}
