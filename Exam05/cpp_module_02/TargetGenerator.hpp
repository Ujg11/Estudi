/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TargetGenerator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojimenez <ojimenez@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 17:02:30 by ojimenez          #+#    #+#             */
/*   Updated: 2024/07/18 17:02:30 by ojimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include "ATarget.hpp"
# include <map>

class TargetGenerator
{
	private:
		TargetGenerator(const TargetGenerator &cpy);
		TargetGenerator &operator=(const TargetGenerator &cpy);

		std::map<std::string, ATarget *> targets;

	public:
		TargetGenerator();
		~TargetGenerator();

		void learnTargetType(ATarget *target);
		void forgetTargetType(std::string const &targetName);
		ATarget *createTarget(std::string const &targetName);
};