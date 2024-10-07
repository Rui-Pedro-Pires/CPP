/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiolive  <ruiolive@student.42.fr   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 16:11:26 by ruiolive          #+#    #+#             */
/*   Updated: 2024/10/04 16:11:26 by ruiolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/iter.hpp"

int main( void )
{
    int array[] = {1, 2, 3, 4, 5};
    for (int i = 0; i < 5; ++i)
        std::cout << array[i] << std::endl;
    std::cout << "------------" << std::endl;
    iter(array, 5, ::function<int>);
    for (int i = 0; i < 5; ++i) {
        std::cout << array[i] << std::endl;
    }
    return 0;
}