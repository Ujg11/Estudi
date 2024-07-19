/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Warlock.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojimenez <ojimenez@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 09:51:19 by ojimenez          #+#    #+#             */
/*   Updated: 2024/07/18 09:51:19 by ojimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Warlock.hpp"

Warlock::Warlock()
{
}

Warlock::Warlock(const Warlock &cpy)
{
	*this = cpy;
}

Warlock &Warlock::operator=(const Warlock &cpy)
{
	this->name = cpy.name;
	this->title = cpy.title;
	return (*this);
}

Warlock::Warlock(std::string name, std::string title): name(name), title(title)
{
	std::cout << this->name << ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock()
{
	std::cout << this->name << ": My job here is done!" << std::endl;
	for (std::map<std::string, ASpell *>::iterator it = spellsCollection.begin(); it != spellsCollection.end(); ++it)
	{
		delete it->second;
	}
	spellsCollection.clear();
}

const std::string &Warlock::getName() const
{
	return (this->name);
}

const std::string &Warlock::getTitle() const
{
	return (this->title);
}

void Warlock::setTitle(std::string const &title)
{
	this->title = title;
}

void Warlock::introduce() const
{
	std::cout << name << ": I am " << name << ", " << title << "!" << std::endl;
}

void Warlock::learnSpell(ASpell *spell)
{
	if (spell)
	{
		if (spellsCollection.find(spell->getName()) == spellsCollection.end())
			spellsCollection[spell->getName()] = spell->clone();
	}
}

void Warlock::forgetSpell(std::string spellName)
{
	std::map<std::string, ASpell *>::iterator it = spellsCollection.find(spellName);

	if (it != spellsCollection.end())
	{
		delete it->second;
		spellsCollection.erase(spellName);
	}
}

void Warlock::launchSpell(std::string spellName, ATarget const &target)
{
	if (spellsCollection.find(spellName) != spellsCollection.end())
		spellsCollection[spellName]->launch(target);
}

