/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiolive  <ruiolive@student.42.fr   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by ruiolive          #+#    #+#             */
/*   Updated: 2024/10/02 23:25:02 by ruiolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Serializer.hpp"

int main(void)
{
    Data* ptr = new Data;
    Data* copy;
    uintptr_t i;

    i = Serializer::serialize(ptr);
    copy = Serializer::deserialize(i);
    std::cout << ptr << std::endl;
    std::cout << copy << std::endl;
    delete copy;
}