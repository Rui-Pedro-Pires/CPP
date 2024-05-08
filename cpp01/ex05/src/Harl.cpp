/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiolive  <ruiolive@student.42.fr   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 16:45:30 by ruiolive          #+#    #+#             */
/*   Updated: 2024/05/08 16:45:33 by ruiolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Harl.hpp"

void Harl::complain( std::string level )
{
}

void Harl::debug( void )
{
    LOG( "debug" );
}

void Harl::info( void )
{
    LOG( "info" );
}

void Harl::warning( void )
{
    LOG( "warning" );
}

void Harl::error( void )
{
    LOG( "error" );
}