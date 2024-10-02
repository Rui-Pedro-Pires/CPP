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

#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>

typedef struct s_sscanf {
  int sscanf_char;
  int sscanf_int;
  int sscanf_float;
  int sscanf_double;
} t_sscanf;

class ScalarConverter {
private:
  ScalarConverter();
  ~ScalarConverter();
  ScalarConverter(const ScalarConverter &other);
  ScalarConverter &operator=(const ScalarConverter &other);

public:
  static void convert(std::string &str);
  static bool ft_isdigit(std::string str);
  static int float_or_double(std::string str);
};

#endif
