/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiolive  <ruiolive@student.42.fr   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 16:45:03 by ruiolive          #+#    #+#             */
/*   Updated: 2024/05/08 16:45:03 by ruiolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __HARL_HPP__
#define __HARL_HPP__

#include <iostream>
#define LOG( x ) std::cout << x << std::endl;

class Harl
{
private:
    int _logLevel;

public:
    void complain( std::string level );

private:
    void debug( void );
    void info( void );
    void warning( void );
    void error( void );
}

#endif