/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dummy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojimenez <ojimenez@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 11:57:08 by ojimenez          #+#    #+#             */
/*   Updated: 2024/07/18 11:57:08 by ojimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dummy.hpp"

Dummy::Dummy()
{
	this->type = "Target Practice Dummy";
}

Dummy::~Dummy()
{

}

ATarget *Dummy::clone() const
{
	return (new Dummy());
}