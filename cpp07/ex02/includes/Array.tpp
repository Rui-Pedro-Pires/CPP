/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                       :+:      :+:    :+:      */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiolive  <ruiolive@student.42.fr   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 16:11:48 by ruiolive          #+#    #+#             */
/*   Updated: 2024/10/04 16:11:48 by ruiolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template<typename T>
Array::Array()
{
    this->array = new T;
}

Array::Array( unsigned int N )
{
    array = new T[N];
};