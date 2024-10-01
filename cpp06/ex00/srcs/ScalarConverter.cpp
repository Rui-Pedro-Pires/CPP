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

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other) {
  if (this != &other)
    return *this;
  return *this;
}

void ScalarConverter::convert(char *str) {
  float str_float;
  double str_double;
  int str_int;
  char str_char;

  if (sscanf(str, "%d", &str_int) == 1) {
    str_char = (char)str_int;
    str_float = (float)str_int;
    str_double = (double)str_int;
  } else if (sscanf(str, "%c", &str_char) == 1) {
    str_int = (int)str_char;
    str_float = (float)str_char;
    str_double = (double)str_char;
  } else if (sscanf(str, "%f", &str_float) == 1) {
    str_int = (int)str_float;
    str_char = (char)str_int;
    str_double = (double)str_float;
  } else if (sscanf(str, "%lf", &str_double) == 1) {
    str_int = (int)str_double;
    str_char = (char)str_int;
    str_float = (float)str_float;
  }
  if (str_char > 20)
    std::cout << "char: " << str_char << std::endl;
  else
    std::cout << "char: Non displayable" << std::endl;
  std::cout << "int: " << str_int << std::endl;
  std::cout << "float: " << str_float << std::endl;
  std::cout << "double: " << str_double << std::endl;
}
