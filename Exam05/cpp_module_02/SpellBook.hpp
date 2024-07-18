/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SpellBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojimenez <ojimenez@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 16:21:55 by ojimenez          #+#    #+#             */
/*   Updated: 2024/07/18 16:21:55 by ojimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include "ASpell.hpp"
# include <map>

class SpellBook
{
	private:
		SpellBook(const SpellBook &cpy);
		SpellBook &operator=(const SpellBook &cpy);

		std::map<std::string, ASpell *> spells;

	public:
		SpellBook();
		~SpellBook();
		void learnSpell(ASpell *spell);
		void forgetSpell(std::string const &spellName);
		ASpell *createSpell(std::string const &spellName);

};
