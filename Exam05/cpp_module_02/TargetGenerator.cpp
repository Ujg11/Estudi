/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TargetGenerator.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojimenez <ojimenez@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 17:02:38 by ojimenez          #+#    #+#             */
/*   Updated: 2024/07/18 17:02:38 by ojimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator()
{
}

TargetGenerator::~TargetGenerator()
{
	for (std::map<std::string, ATarget *>::iterator it = targets.begin(); it != targets.end(); ++it)
	{
		delete it->second;
	}
	targets.clear();
}

TargetGenerator::TargetGenerator(const TargetGenerator &cpy)
{
	*this = cpy;
}

TargetGenerator &TargetGenerator::operator=(const TargetGenerator &cpy)
{
	if (this != &cpy)
	{
		this->targets = cpy.targets;
	}
	return (*this);
}

void TargetGenerator::learnTargetType(ATarget *target)
{
	if (target)
	{
		if (targets.find(target->getType()) == targets.end())
			targets[target->getType()] = target->clone();
	}
}

void TargetGenerator::forgetTargetType(std::string const &targetName)
{
	std::map<std::string, ATarget *>::iterator it = targets.find(targetName);

	if (it != targets.end())
	{
		delete it->second;
		targets.erase(it);
	}
}

ATarget *TargetGenerator::createTarget(std::string const &targetName)
{
	ATarget *t = NULL;

	if (targets.find(targetName) != targets.end())
		t = targets[targetName]->clone();
	return (t);
}
