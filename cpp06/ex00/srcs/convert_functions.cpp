/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_functions.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiolive  <ruiolive@student.42.fr   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 16:46:13 by ruiolive          #+#    #+#             */
/*   Updated: 2024/10/03 16:46:13 by ruiolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScalarConverter.hpp"

void character_case(std::string str)
{
    float str_float;
    double str_double;
    long str_int;
    char str_char;

    str_char = str[0];
    str_int = static_cast<int>(str_char);
    str_float = static_cast<float>(str_char);
    str_double = static_cast<double>(str_char);
    std::cout << "char: " << str_char << std::endl;
    std::cout << "int: " << str_int << std::endl;
    std::cout << "float: " << str_float << ".0f" << std::endl;
    std::cout << "double: " << str_double << ".0" << std::endl;
}

void int_case(std::string str)
{
    float str_float;
    double str_double;
    long str_int;
    char str_char;
    errno = 0;

    str_int = strtol(str.c_str(), NULL, 10);
    str_char = static_cast<char>(str_int);
    str_float = static_cast<float>(str_int);
    str_double = static_cast<double>(str_int);
    if (errno == ERANGE || str_int > INT_MAX || str_int < INT_MIN)
        return error_information();
    if ((str_int < 32 && str_int >= 0) || (str_int < 256 && str_int > 126))
        std::cout << "char: Non displayable" << std::endl;
    else if (str_int < 0 || str_int > 255)
        std::cout << "char: impossible" << std::endl;
    else
        std::cout << "char: " << str_char << std::endl;
    std::cout << "int: " << str_int << std::endl;
    std::cout << "float: " << str_float << ".0f" << std::endl;
    std::cout << "double: " << str_double << ".0" << std::endl;
}

void float_case(std::string str)
{
    float str_float;
    double str_double;
    long str_int;
    char str_char;
    errno = 0;

    str_float = strtof(str.c_str(), NULL);
    str_int = static_cast<int>(str_float);
    str_char = static_cast<char>(str_int);
    str_double = static_cast<double>(str_float);
    if (errno == ERANGE)
        return error_information();
    if ((str_int < 32 && str_int >= 0) || (str_int < 256 && str_int > 126))
        std::cout << "char: Non displayable" << std::endl;
    else if (str_int < 0 || str_int > 255)
        std::cout << "char: impossible" << std::endl;
    else
        std::cout << "char: " << str_char << std::endl;
    if (str_float <= static_cast<float>(INT_MAX) && str_float >= static_cast<float>(INT_MIN))
        std::cout << "int: " << str_int << std::endl;
    else
        std::cout << "int: impossible" << std::endl;
    if (str_float - floor(str_float) < 1e-7)
        std::cout << "float: " << str_float << ".0f" << std::endl;
    else
        std::cout << "float: " << str_float << "f" << std::endl;
    if (str_double - floor(str_double) < 1e-7)
        std::cout << "double: " << str_double << ".0" << std::endl;
    else
        std::cout << "double: " << str_double << std::endl;
}

void double_case(std::string str)
{
    float str_float;
    double str_double;
    long str_int;
    char str_char;
    errno = 0;

    str_double = strtod(str.c_str(), NULL);
    str_int = static_cast<int>(str_double);
    str_char = static_cast<char>(str_int);
    str_float = static_cast<float>(str_double);
    if (errno == ERANGE)
        return error_information();
    if ((str_int < 32 && str_int >= 0) || (str_int < 256 && str_int > 126))
        std::cout << "char: Non displayable" << std::endl;
    else if (str_int < 0 || str_int > 255)
        std::cout << "char: impossible" << std::endl;
    else
        std::cout << "char: " << str_char << std::endl;
    if (str_double <= static_cast<double>(INT_MAX) && str_double >= static_cast<double>(INT_MIN))
        std::cout << "int: " << str_int << std::endl;
    else
        std::cout << "int: impossible" << std::endl;
    if ((str_double > static_cast<double>(FLT_MAX) || str_double < static_cast<double>(-FLT_MAX)) && str_double != INFINITY)
        std::cout << "float: impossible" << std::endl;
    else if (str_float - floor(str_float) < 1e-7)
        std::cout << "float: " << str_float << ".0f" << std::endl;
    else
        std::cout << "float: " << str_float << "f" << std::endl;
    if (str_double - floor(str_double) < 1e-7)
        std::cout << "double: " << str_double << ".0" << std::endl;
    else
        std::cout << "double: " << str_double << std::endl;
}

void error_information(void)
{
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: impossible" << std::endl;
    std::cout << "double: impossible" << std::endl;
}
