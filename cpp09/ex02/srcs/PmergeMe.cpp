/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiolive  <ruiolive@student.42.fr   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 09:35:06 by ruiolive          #+#    #+#             */
/*   Updated: 2024/10/17 09:35:06 by ruiolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PmergeMe.hpp"

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

size_t jacobthal(size_t n)
{
    if (n == 0)
        return (0);
    if (n == 1)
        return (1);
    return jacobthal(n - 1) + 2 * jacobthal(n - 2);
}
