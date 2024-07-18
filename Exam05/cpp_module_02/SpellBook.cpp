/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SpellBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojimenez <ojimenez@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 16:22:17 by ojimenez          #+#    #+#             */
/*   Updated: 2024/07/18 16:22:17 by ojimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SpellBook.hpp"

SpellBook::SpellBook(const SpellBook &cpy)
{
	*this = cpy;
}

SpellBook &SpellBook::operator=(const SpellBook &cpy)
{
	if (this != &cpy)
	{
		this->spells = cpy.spells;
	}
	return (*this);
}

SpellBook::SpellBook()
{

}

SpellBook::~SpellBook()
{
	for (std::map<std::string, ASpell *>::iterator it = spells.begin(); it != spells.end(); ++it)
	{
		delete it->second;
	}
	spells.clear();
}

void SpellBook::learnSpell(ASpell *spell)
{
	if (spell)
	{
		if (spells.find(spell->getName()) == spells.end())
			spells[spell->getName()] = spell->clone();
	}
}

void SpellBook::forgetSpell(std::string const &spellName)
{
	for (std::map<std::string, ASpell *>::iterator it = spells.begin(); it != spells.end(); ++it)
	{
		if (it->first == spellName)
		{
			delete it->second;
			spells.erase(it);
			return ;
		}
	}
}

ASpell *SpellBook::createSpell(std::string const &spellName)
{
	ASpell *tmp;

	if (spells.find(spellName) != spells.end())
	{
		tmp = spells[spellName]->clone();
	}
	return (tmp);
}
