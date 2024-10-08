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
MutantStack<T>::MutantStack() : std::stack<T>()
{
}

template <typename T>
MutantStack<T>::~MutantStack()
{
}

template <typename T>
MutantStack<T>::MutantStack( const MutantStack &other ) : std::stack<T>( other )
{
}

template <typename T>
MutantStack<T> &MutantStack<T>::operator=( const MutantStack &other )
{
    if ( this != &other )
        this->c = other.c;
    return *this;
}

template <typename T>
typename MutantStack<T>::Iterator MutantStack<T>::begin()
{
    MutantStack<T>::Iterator it( *this, 0 );
    return it;
}

template <typename T>
typename MutantStack<T>::Iterator MutantStack<T>::end()
{
    MutantStack<T>::Iterator it( *this, this->size() );
    return it;
}

template <typename T>
MutantStack<T>::Iterator::Iterator( MutantStack<T> &mutantStack, unsigned int idx )
    : _mutantStack( mutantStack ), _idx( idx )
{
}

template <typename T>
MutantStack<T>::Iterator::~Iterator()
{
}

template <typename T>
MutantStack<T>::Iterator::Iterator( const MutantStack<T>::Iterator &other )
    : _mutantStack( other._mutantStack ), _idx( other._idx )
{
}

template <typename T>
typename MutantStack<T>::Iterator &MutantStack<T>::Iterator::operator=(
    const MutantStack<T>::Iterator &other )
{
    this->_mutantStack = other._mutantStack;
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
typename MutantStack<T>::Iterator &MutantStack<T>::Iterator::operator++( int )
{
    Iterator tmp = *this;
    this->_idx++;
    return tmp;
}

template <typename T>
typename MutantStack<T>::Iterator &MutantStack<T>::Iterator::operator--( int )
{
    Iterator tmp = *this;
    this->_idx--;
    return tmp;
}

template <typename T>
T &MutantStack<T>::Iterator::operator*()
{
    return this->_mutantStack.c.at( this->_idx );
}

template <typename T>
bool MutantStack<T>::Iterator::operator==( const MutantStack<T>::Iterator &other )
{
    if ( this->_mutantStack == other._mutantStack && this->_idx == other._idx )
        return true;
    return false;
}

template <typename T>
bool MutantStack<T>::Iterator::operator!=( const MutantStack<T>::Iterator &other )
{
    return !( *this == other );
}