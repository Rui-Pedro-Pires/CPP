/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiolive  <ruiolive@student.42.fr   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 21:31:01 by ruiolive          #+#    #+#             */
/*   Updated: 2024/10/07 21:31:01 by ruiolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename T>
MutantStack<T>::MutantStack()
{
}

template <typename T>
MutantStack<T>::~MutantStack()
{
}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack &other) : std::stack<T>(other)
{
}

template <typename T>
MutantStack<T> &MutantStack<T>::operator=(const MutantStack &other)
{
    (void)other;
    return *this;
}

template <typename T>
Iterator MutantStack<T>::begin()
{
    Iterator it(this, 0);
    return it;
}

template <typename T>
Iterator MutantStack<T>::end()
{
    Iterator it(this, this->size());
    return it;
}

template <typename T>
MutantStack<T>::Iterator::Iterator(T &vec, unsigned int idx) : _vec(vec), _idx(idx)
{
}

template <typename T>
MutantStack<T>::Iterator::~Iterator()
{
}

template <typename T>
MutantStack<T>::Iterator::Iterator(const Iterator &other) : _vec(other._vec), _idx(other._idx)
{
}

template <typename T>
MutantStack<T>::Iterator &MutantStack<T>::Iterator::operator=(const Iterator &other)
{
    this->_vec = other._vec;
    this->_idx = other._idx;
    return *this;
}

template <typename T>
MutantStack<T>::Iterator &MutantStack<T>::Iterator::operator++()
{
    this->_idx++;
    return *this;
}

template <typename T>
MutantStack<T>::Iterator &MutantStack<T>::Iterator::operator--()
{
    this->_idx--;
    return *this;
}

template <typename T>
MutantStack<T>::Iterator &MutantStack<T>::Iterator::operator++(int)
{
    Iterator tmp = *this;
    this->_idx++;
    return tmp;
}

template <typename T>
MutantStack<T>::Iterator &MutantStack<T>::Iterator::operator--(int)
{
    Iterator tmp = *this;
    this->_idx--;
    return tmp;
}
