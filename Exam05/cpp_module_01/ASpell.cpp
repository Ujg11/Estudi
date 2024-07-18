/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ASpell.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojimenez <ojimenez@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 10:47:25 by ojimenez          #+#    #+#             */
/*   Updated: 2024/07/18 10:47:25 by ojimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ASpell.hpp"

ASpell::ASpell(): name("defaultName"), effects("defaultEffects")
{
}

ASpell::ASpell(std::string n, std::string eff): name(n), effects(eff)
{
}

ASpell::ASpell(const ASpell &cpy)
{
	*this = cpy;
}

ASpell &ASpell::operator=(const ASpell &cpy)
{
	if (this != &cpy)
	{
		this->name = cpy.name;
		this->effects = cpy.effects;
	}
	return (*this);
}

ASpell::~ASpell()
{

}

std::string ASpell::getName() const
{
	return (this->name);
}

std::string ASpell::getEffects() const
{
	return (this->effects);
}

void ASpell::launch(const ATarget &target) const
{
	target.getHitBySpell(*this);
}
