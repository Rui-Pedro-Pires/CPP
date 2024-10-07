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

template <typename T>
int easyfind(T container, int to_search)
{
    T<int>::iterator it;
    it = container.find(container.begin(), container.end(), to_search);
    if (!it)
        return throw std::exception(); 
    else return (0);
}

#endif