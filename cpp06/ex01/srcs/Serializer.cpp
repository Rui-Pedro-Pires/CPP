/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiolive  <ruiolive@student.42.fr   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by ruiolive          #+#    #+#             */
/*   Updated: 2024/10/02 23:25:10 by ruiolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Serializer.hpp"

Serializer::Serializer() {}

Serializer::~Serializer() {}

Serializer::Serializer(const Serializer &other) { (void)other; }

Serializer &Serializer::operator=(const Serializer &other) {
  (void)other;
  return *this;
}

uintptr_t Serializer::serialize(Data *ptr) {
  if (!ptr)
    return (0);
  return reinterpret_cast<uintptr_t>(ptr);
}

Data *Serializer::deserialize(uintptr_t raw) {
  if (!raw)
    return(NULL);
  return reinterpret_cast<Data *>(raw);
}
