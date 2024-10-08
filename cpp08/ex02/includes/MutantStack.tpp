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
typename MutantStack<T>::Iterator MutantStack<T>::begin()
{
    MutantStack<T>::Iterator it(*this, 0);
    return it;
}

template <typename T>
typename MutantStack<T>::Iterator MutantStack<T>::end()
{
    MutantStack<T>::Iterator it(*this, this->size());
    return it;
}

template <typename T>
MutantStack<T>::Iterator::Iterator(MutantStack<T> &vec, unsigned int idx) : _stack(vec), _idx(idx)
{
}

template <typename T>
MutantStack<T>::Iterator::~Iterator()
{
}

template <typename T>
MutantStack<T>::Iterator::Iterator(const MutantStack<T>::Iterator &other) : _stack(other._stack), _idx(other._idx)
{
}

template <typename T>
typename MutantStack<T>::Iterator &MutantStack<T>::Iterator::operator=(const MutantStack<T>::Iterator &other)
{
    this->_stack = other._stack;
    this->_idx = other._idx;
    return *this;
}

template <typename T>
typename MutantStack<T>::Iterator &MutantStack<T>::Iterator::operator++()
{
    this->_idx++;
    return *this;
}

template <typename T>
typename MutantStack<T>::Iterator &MutantStack<T>::Iterator::operator--()
{
    this->_idx--;
    return *this;
}

template <typename T>
typename MutantStack<T>::Iterator &MutantStack<T>::Iterator::operator++(int)
{
    Iterator tmp = *this;
    this->_idx++;
    return tmp;
}

template <typename T>
typename MutantStack<T>::Iterator &MutantStack<T>::Iterator::operator--(int)
{
    Iterator tmp = *this;
    this->_idx--;
    return tmp;
}

template <typename T>
T& MutantStack<T>::Iterator::operator*()
{
    return this->_stack.c.at(this->_idx);
}

template <typename T>
bool MutantStack<T>::Iterator::operator==(const MutantStack<T>::Iterator& other)
{
    if (this->_stack == other._stack && this->_idx == other._idx)
        return true;
    return false;
}

template <typename T>
bool MutantStack<T>::Iterator::operator!=(const MutantStack<T>::Iterator& other)
{
    return !(*this == other);
}