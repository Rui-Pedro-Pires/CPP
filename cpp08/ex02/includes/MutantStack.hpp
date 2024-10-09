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

#include <bits/stdc++.h>

#include <iostream>

template <typename T, typename ContainerType = std::deque<T>>
class MutantStack : public std::stack<T, ContainerType>
{
public:
    MutantStack();
    ~MutantStack();
    MutantStack(const MutantStack &other);
    MutantStack &operator=(const MutantStack &other);

    typedef typename ContainerType::iterator iterator;
    typedef typename ContainerType::const_iterator const_iterator;
    typedef typename ContainerType::reverse_iterator reverse_iterator;
    typedef typename ContainerType::const_reverse_iterator const_reverse_iterator;

    iterator begin();
    iterator end();
    const_iterator cbegin();
    const_iterator cend();
    reverse_iterator rbegin();
    reverse_iterator rend();
    const_reverse_iterator crbegin();
    const_reverse_iterator crend();

    // class Iterator
    // {
    // private:
    //     MutantStack<T, ContainerType> &_mutantStack;
    //     unsigned int _idx;

    // public:
    //     Iterator( MutantStack<T, ContainerType> &mutantStack, unsigned int idx );
    //     ~Iterator();
    //     Iterator( const Iterator &other );
    //     Iterator &operator=( const Iterator &other );

    //     Iterator &operator++();
    //     Iterator &operator--();
    //     Iterator &operator++( int );
    //     Iterator &operator--( int );
    //     T &operator*();
    //     bool operator==( const Iterator &other );
    //     bool operator!=( const Iterator &other );
    // };

    // typedef typename MutantStack<T, ContainerType>::Iterator iterator;
};

#include "MutantStack.tpp"

#endif