/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiolive  <ruiolive@student.42.fr   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 15:50:57 by ruiolive          #+#    #+#             */
/*   Updated: 2024/10/01 15:50:57 by ruiolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef ScalarConverter_HPP
#define ScalarConverter_HPP

#include <errno.h>
#include <limits.h>
#include <float.h>
#include <stdlib.h>
#include <cstring>
#include <cmath>
#include <iomanip>
#include <iostream>

enum Type
{
  C,
  I,
  F,
  D,
  ERR
};

class ScalarConverter
{
private:
  ScalarConverter();
  ~ScalarConverter();
  ScalarConverter(const ScalarConverter &other);
  ScalarConverter &operator=(const ScalarConverter &other);

public:
  static void convert(std::string &str);
};

bool ft_isdigit(std::string str);
int float_or_double(std::string str);
int check_if_int(std::string str);
void characterCase(std::string str);
void intCase(std::string str);
void floatCase(std::string str);
void doubleCase(std::string str);
void errorInformation(void);

#endif
