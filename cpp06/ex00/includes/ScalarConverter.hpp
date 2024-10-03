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
int check_special_cases(std::string str);
void character_case(std::string str);
void int_case(std::string str);
void float_case(std::string str);
void double_case(std::string str);
void error_information(void);

#endif
