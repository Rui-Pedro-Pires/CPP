/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiolive  <ruiolive@student.42.fr   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 12:17:04 by ruiolive          #+#    #+#             */
/*   Updated: 2024/10/07 12:17:04 by ruiolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>

template <typename T>
int easyfind(T container, int to_search)
{
    if (std::find(container.begin(), container.end(), to_search) == container.end())
        throw std::exception(); 
    return (0);
}

#endif