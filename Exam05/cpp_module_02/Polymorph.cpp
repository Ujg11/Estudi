/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Polymorph.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojimenez <ojimenez@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 15:47:27 by ojimenez          #+#    #+#             */
/*   Updated: 2024/07/18 15:47:27 by ojimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Polymorph.hpp"

Polymorph::Polymorph()
{
	this->name = "Polymorph";
	this->effects = "turned into a critter";
}

Polymorph::~Polymorph()
{
}

ASpell *Polymorph::clone() const
{
	return (new Polymorph());
}