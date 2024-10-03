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
    Data data;
    data.x = 4;
    data.y = 5;
    Data *ptr = &data;
    Data *copy;
    uintptr_t i;

    std::cout << "Original x:" << data.x << std::endl;
    std::cout << "Original y:" << data.y << std::endl;
    i = Serializer::serialize(ptr);
    copy = Serializer::deserialize(i);
    std::cout << "Copy x:" << data.x << std::endl;
    std::cout << "Copy y:" << data.y << std::endl;
    std::cout << ptr << std::endl;
    std::cout << copy << std::endl;
}