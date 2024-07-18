/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ASpell.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojimenez <ojimenez@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 10:47:18 by ojimenez          #+#    #+#             */
/*   Updated: 2024/07/18 10:47:18 by ojimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include "ATarget.hpp"

class ATarget;

class ASpell
{
	protected:
		std::string name;
		std::string effects;
	
	public:
		ASpell();
		ASpell(std::string n, std::string eff);
		ASpell(const ASpell &cpy);
		ASpell &operator=(const ASpell &cpy);
		virtual ~ASpell();

		std::string getName() const;
		std::string getEffects() const;
		virtual ASpell *clone() const = 0;

		void launch(const ATarget &target) const;
};