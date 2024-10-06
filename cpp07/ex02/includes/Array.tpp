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


template<typename T>
Array<T>::Array()
{
    this->array = new T;
}

template<typename T>
Array<T>::Array( unsigned int N )
{
    array = new T[N];
}

template<typename T>
Array<T>::~Array()
{
    if (this->array)
        delete[] this->array;
}

template<typename T>
Array<T>::Array(const Array &other)
{
    (void) other;
}

template<typename T>
Array<T>& Array<T>::operator=( const Array& other )
{
    (void) other;
    return *this;
}

template<typename T>
T& Array<T>::operator[]( int i )
{
    return array[i];
}

template<typename T>
int Array<T>::size()
{
    int i = 0;
    while (this->array[i])
        i++;
    return i;
}