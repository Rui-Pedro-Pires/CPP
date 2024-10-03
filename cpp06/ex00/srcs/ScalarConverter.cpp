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
    return errorInformation();
  switch (type)
  {
  case C:
    characterCase(str);
    break;
  case I:
    intCase(str);
    break;
  case F:
    floatCase(str);
    break;
  case D:
    doubleCase(str);
    break;
  default:
    break;
  }
}
