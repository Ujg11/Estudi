/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ATarget.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojimenez <ojimenez@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 11:30:11 by ojimenez          #+#    #+#             */
/*   Updated: 2024/07/18 11:30:11 by ojimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ATarget.hpp"

ATarget::ATarget()
{
	this->type = "defaultType";
}

ATarget::ATarget(std::string type)
{
	this->type = type;
}

ATarget::ATarget(const ATarget &cpy)
{
	*this = cpy;
}

ATarget &ATarget::operator=(const ATarget &cpy)
{
	if (this != &cpy)
	{
		this->type = cpy.type;
	}
	return (*this);
}

ATarget::~ATarget()
{

}

const std::string &ATarget::getType() const
{
	return (this->type);
}

void ATarget::getHitBySpell(const ASpell &spell) const
{
	std::cout << type << " has been " << spell.getEffects() << "!" << std::endl;
}