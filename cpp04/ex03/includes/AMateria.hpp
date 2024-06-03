/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiolive  <ruiolive@student.42.fr   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 16:41:45 by ruiolive          #+#    #+#             */
/*   Updated: 2024/06/03 16:41:45 by ruiolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __AMATERIA_H__
#define __AMATERIA_H__

class AMateria
{
private:

public:
    AMateria();
    ~AMateria();
    AMateria(const AMateria& originalAMateria);
    AMateria& operator=(const AMateria& originalAMateria);
};
#endif