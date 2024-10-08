/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiolive  <ruiolive@student.42.fr   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 21:31:01 by ruiolive          #+#    #+#             */
/*   Updated: 2024/10/07 21:31:01 by ruiolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
public:
    MutantStack();
    ~MutantStack();
    MutantStack(const MutantStack &other);
    MutantStack &operator=(const MutantStack &other);

    class Iterator
    {
    private:
        T &_pointer;
        unsigned int _idx;

    public:
        Iterator(T &pointer, unsigned int idx);
        ~Iterator();
        Iterator(const Iterator &other);
        Iterator &operator=(const Iterator &other);

        Iterator &operator++();
        Iterator &operator--();
        Iterator &operator++(int);
        Iterator &operator--(int);
    };

    Iterator begin();
    Iterator end();

    typedef typename MutantStack<T>::Iterator iterator;
};

#include "MutantStack.tpp"

#endif