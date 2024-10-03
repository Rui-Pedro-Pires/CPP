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
#include <stdlib.h>
#include <cstring>
#include <iomanip>
#include <iostream>

typedef struct s_sscanf
{
  int sscanf_char;
  int sscanf_int;
  int sscanf_float;
  int sscanf_double;
} t_sscanf;

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
void num_information(char str_char, long str_int, float str_float, double str_double);
void error_information(void);

#endif
