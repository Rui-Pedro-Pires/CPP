/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiolive  <ruiolive@student.42.fr   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 13:36:42 by ruiolive          #+#    #+#             */
/*   Updated: 2024/06/03 13:36:42 by ruiolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __BRAIN_H__
#define __BRAIN_H__

#include <iostream>

class Brain
{
private:
    std::string _ideas[100];

public:
    Brain();
    Brain( const Brain& other );
    Brain& operator=( const Brain& other );
    ~Brain();
};

#endif