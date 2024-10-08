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

template <typename T, typename ContainerType>
MutantStack<T, ContainerType>::MutantStack() : std::stack<T, ContainerType>()
{
}

template <typename T, typename ContainerType>
MutantStack<T, ContainerType>::~MutantStack()
{
}

template <typename T, typename ContainerType>
MutantStack<T, ContainerType>::MutantStack( const MutantStack &other )
    : std::stack<T, ContainerType>( other )
{
}

template <typename T, typename ContainerType>
MutantStack<T, ContainerType> &MutantStack<T, ContainerType>::operator=( const MutantStack &other )
{
    if ( this != &other )
        this->c = other.c;
    return *this;
}

template <typename T, typename ContainerType>
typename MutantStack<T, ContainerType>::iterator MutantStack<T, ContainerType>::begin()
{
    return this->c.begin();
}

template <typename T, typename ContainerType>
typename MutantStack<T, ContainerType>::iterator MutantStack<T, ContainerType>::end()
{
    return this->c.end();
}

// template <typename T, typename ContainerType>
// typename MutantStack<T, ContainerType>::Iterator MutantStack<T, ContainerType>::begin()
// {
//     MutantStack<T, ContainerType>::Iterator it( *this, 0 );
//     return it;
// }

// template <typename T, typename ContainerType>
// typename MutantStack<T, ContainerType>::Iterator MutantStack<T, ContainerType>::end()
// {
//     MutantStack<T, ContainerType>::Iterator it( *this, this->size() );
//     return it;
// }

// template <typename T, typename ContainerType>
// MutantStack<T, ContainerType>::Iterator::Iterator( MutantStack<T, ContainerType> &mutantStack,
// unsigned int idx )
//     : _mutantStack( mutantStack ), _idx( idx )
// {
// }

// template <typename T, typename ContainerType>
// MutantStack<T, ContainerType>::Iterator::~Iterator()
// {
// }

// template <typename T, typename ContainerType>
// MutantStack<T, ContainerType>::Iterator::Iterator( const MutantStack<T, ContainerType>::Iterator
// &other )
//     : _mutantStack( other._mutantStack ), _idx( other._idx )
// {
// }

// template <typename T, typename ContainerType>
// typename MutantStack<T, ContainerType>::Iterator &MutantStack<T,
// ContainerType>::Iterator::operator=(
//     const MutantStack<T, ContainerType>::Iterator &other )
// {
//     this->_mutantStack = other._mutantStack;
//     this->_idx = other._idx;
//     return *this;
// }

// template <typename T, typename ContainerType>
// typename MutantStack<T, ContainerType>::Iterator &MutantStack<T,
// ContainerType>::Iterator::operator++()
// {
//     this->_idx++;
//     return *this;
// }

// template <typename T, typename ContainerType>
// typename MutantStack<T, ContainerType>::Iterator &MutantStack<T,
// ContainerType>::Iterator::operator--()
// {
//     this->_idx--;
//     return *this;
// }

// template <typename T, typename ContainerType>
// typename MutantStack<T, ContainerType>::Iterator &MutantStack<T,
// ContainerType>::Iterator::operator++( int )
// {
//     Iterator tmp = *this;
//     this->_idx++;
//     return tmp;
// }

// template <typename T, typename ContainerType>
// typename MutantStack<T, ContainerType>::Iterator &MutantStack<T,
// ContainerType>::Iterator::operator--( int )
// {
//     Iterator tmp = *this;
//     this->_idx--;
//     return tmp;
// }

// template <typename T, typename ContainerType>
// T &MutantStack<T, ContainerType>::Iterator::operator*()
// {
//     if constexpr (std::is_same<ContainerType, std::list<T>>::value) {
//         typename ContainerType::iterator it = this->_mutantStack.c.begin();
//         std::advance(it, this->_idx);
//         return *it;
//     } else {
//         return this->_mutantStack.c.at(this->_idx);
//     }
// }

// template <typename T, typename ContainerType>
// bool MutantStack<T, ContainerType>::Iterator::operator==( const MutantStack<T,
// ContainerType>::Iterator &other )
// {
//     if ( this->_mutantStack == other._mutantStack && this->_idx == other._idx )
//         return true;
//     return false;
// }

// template <typename T, typename ContainerType>
// bool MutantStack<T, ContainerType>::Iterator::operator!=( const MutantStack<T,
// ContainerType>::Iterator &other )
// {
//     return !( *this == other );
// }