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
    ACTIONS menu[] = {
        &Harl::debug,
        &Harl::info,
        &Harl::warning,
        &Harl::error
    };

    std::string actions[] = {
        "DEBUG",
        "INFO",
        "WARNING",
        "ERROR"
    };

    for (int i = 0; i < 4; i++) {
        if (actions[i] == level)
            (this->*menu[i])();
    }
}

void Harl::debug( void )
{
    LOG( "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" );
}

void Harl::info( void )
{
    LOG( "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" );
}

void Harl::warning( void )
{
    LOG( "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." );
}

void Harl::error( void )
{
    LOG( "This is unacceptable! I want to speak to the manager now." );
}

