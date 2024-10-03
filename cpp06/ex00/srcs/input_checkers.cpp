/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_checkers.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiolive  <ruiolive@student.42.fr   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 10:23:57 by ruiolive          #+#    #+#             */
/*   Updated: 2024/10/03 10:23:57 by ruiolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScalarConverter.hpp"

bool ft_isdigit(std::string str)
{
    std::string::iterator itr;
    for (itr = str.begin(); itr < str.end(); itr++)
    {
        if (!isdigit(*itr))
            return (false);
    }
    return (true);
}

int check_if_int(std::string str)
{
    size_t i = 0;
    if (str[i] == '-' || str[i] == '+')
        i++;
    while (i < str.length())
    {
        if (!isdigit(str[i]))
            return (0);
        i++;
    }
    return (1);
}

int float_or_double(std::string str)
{
    bool as_f = false;
    bool as_dot = false;
    size_t index_dot;
    size_t index_f;
    size_t i = 0;
    if (str == "nanf" || str == "+inff" || str == "-inff" || str == "inff")
        return (1);
    if (str == "nan" || str == "+inf" || str == "-inf" || str == "inf")
        return (2);
    if (str[i] == '-' || str[i] == '+')
        i++;
    if (i == str.length() - 1)
        return (0);
    while (i < str.length())
    {
        if (!isdigit(str[i]) && !strchr(".f", str[i]))
            return (0);
        i++;
    }
    index_dot = str.find('.');
    index_f = str.find('f');
    if (index_dot != std::string::npos)
    {
        if (index_dot == 0 || index_dot == (str.length() - 1))
            return (0);
        as_dot = true;
    }
    if (index_f != std::string::npos)
    {
        if (index_f != (str.length() - 1))
            return (0);
        as_f = true;
    }
    if (as_dot && as_f)
    {
        if (index_dot - index_f == 1)
            return (0);
        return (1);
    }
    else if (as_dot && !as_f)
        return (2);
    return (1);
}
