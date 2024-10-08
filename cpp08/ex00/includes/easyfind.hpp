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
#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>

template <typename T>
int easyfind(T container, int to_search)
{
    typename T::iterator it;

    it = std::find(container.begin(), container.end(), to_search);
    if (it == container.end())
        throw std::out_of_range("Number not found!");
    return (std::distance(container.begin(), it));
}

#endif