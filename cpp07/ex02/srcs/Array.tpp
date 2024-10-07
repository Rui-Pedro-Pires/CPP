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

#include "../includes/Array.hpp"

template<typename T>
Array<T>::Array()
{
    _size = 0;
    array = new T;
}

template<typename T>
Array<T>::Array( unsigned int N )
{
    _size = N;
    array = new T[N];
}

template<typename T>
Array<T>::~Array()
{
    delete[] this->array;
}

template<typename T>
Array<T>::Array( const Array &other) : _size(other.size())
{
    this->array = new T[other.size()];
    for (int i = 0; i < other.size(); i++)
        this->array[i] = other.array[i];
}

template<typename T>
Array<T>& Array<T>::operator=( const Array& other )
{
    if (this != &other)
    {
        delete[] this->array;
        this->_size = other.size();
        this->array = new T[other.size()];
        for (int i = 0; i < other.size(); i++)
            this->array[i] = other.array[i];
    }
    return *this;
}

template<typename T>
const T& Array<T>::operator[]( int i ) const
{
    if (i >= this->size() || i < 0)
        throw OverflowIndexException();
    return array[i];
}

template<typename T>
T& Array<T>::operator[]( int i )
{
    if (i >= this->size() || i < 0)
        throw OverflowIndexException();
    return array[i];
}

template<typename T>
int Array<T>::size() const
{
    return this->_size;
}

template<typename T>
const char* Array<T>::OverflowIndexException::what() const throw() 
{
    return "Index is out of bounds";
}