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

void ScalarConverter::convert(std::string &str) {
  float str_float;
  double str_double;
  int str_int;
  char str_char;

  if (str.size() == 1 && !ScalarConverter::ft_isdigit(str)) {
    sscanf(str.c_str(), "%c", &str_char);
    str_int = static_cast<int>(str_char);
    str_float = static_cast<float>(str_char);
    str_double = static_cast<double>(str_char);
  } else if (ScalarConverter::ft_isdigit(str)) {
    sscanf(str.c_str(), "%d", &str_int);
    str_char = static_cast<char>(str_int);
    str_float = static_cast<float>(str_int);
    str_double = static_cast<double>(str_int);
  } else if (ScalarConverter::float_or_double(str) == 1) {
    sscanf(str.c_str(), "%f", &str_float);
    str_int = static_cast<int>(str_float);
    str_char = static_cast<char>(str_int);
    str_double = static_cast<double>(str_float);
  } else if (ScalarConverter::float_or_double(str) == 2) {
    sscanf(str.c_str(), "%lf", &str_double);
    str_int = static_cast<int>(str_double);
    str_char = static_cast<char>(str_int);
    str_float = static_cast<float>(str_double);
  } else if (ScalarConverter::float_or_double(str) == 0) {
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: impossible" << std::endl;
    std::cout << "double: impossible" << std::endl;
    return;
  }
  if (str_char > 32)
    std::cout << "char: " << str_char << std::endl;
  else
    std::cout << "char: Non displayable" << std::endl;
  std::cout << "int: " << str_int << std::endl;
  std::cout << "float: " << str_float << "f" << std::endl;
  std::cout << "double: " << str_double << std::endl;
}

bool ScalarConverter::ft_isdigit(std::string str) {
  std::string::iterator itr;
  for (itr = str.begin(); itr < str.end(); itr++) {
    if (!isdigit(*itr) && *itr != '+' && *itr != '-')
      return (false);
  }
  return (true);
}

int ScalarConverter::float_or_double(std::string str) {
  bool as_f = false;
  bool as_dot = false;
  size_t index_dot;
  size_t index_f;
  size_t index_minus;
  size_t index_plus;
  for (size_t i = 0; i < str.length(); i++) {
    if (!isdigit(str[i]) && !strchr(".f-+", str[i]))
      return (0);
  }
  index_dot = str.find('.');
  index_f = str.find('f');
  index_minus = str.find('-');
  index_plus = str.find('+');
  if (index_minus != std::string::npos && index_minus != 0)
    return (0);
  if (index_plus != std::string::npos && index_plus != 0)
    return (0);
  if (index_dot != std::string::npos) {
    if (index_dot == 0 || index_dot == (str.length() - 1))
      return (0);
    as_dot = true;
  }
  if (index_f != std::string::npos) {
    if (index_f != (str.length() - 1))
      return (0);
    as_f = true;
  }
  if (as_dot && as_f) {
    if (abs(index_dot - index_f) == 1)
      return (0);
    return (1);
  } else if (as_dot && !as_f)
    return (2);
  return (1);
}