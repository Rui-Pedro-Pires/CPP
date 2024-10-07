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
MutantStack::MutantStack(const MutantStack& other)
{
    int size = other.size();
    for (size_t i = 0; i < size; i++)
    {
        this->push(other[i]);
    }
}

// template <typename T>
// MutantStack& MutantStack::operator=(const MutantStack& other)
// {
// }

template <typename T>
int MutantStack<T>::empty()
{
    return this->stack.empty();
}
template <typename T>
int MutantStack<T>::size()
{
    return this->stack.size();
}

template <typename T>
T& MutantStack<T>::top()
{
    return this->stack.top();
}

template <typename T>
void MutantStack<T>::push(T toPush)
{
    this->stack.push(toPush);
}

template <typename T>
void MutantStack<T>::pop()
{
    this->stack.pop();
}