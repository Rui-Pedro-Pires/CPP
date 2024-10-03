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
  Type type;

  if (str.size() == 1 && !ft_isdigit(str))
    type = C;
  else if (check_if_int(str))
    type = I;
  else if (float_or_double(str) == 1)
    type = F;
  else if (float_or_double(str) == 2)
    type = D;
  else
    return error_information();
  switch (type)
  {
  case C:
    character_case(str);
    break;
  case I:
    int_case(str);
    break;
  case F:
    float_case(str);
    break;
  case D:
    double_case(str);
    break;
  default:
    break;
  }
}
