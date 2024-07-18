/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ATarget.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojimenez <ojimenez@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 11:30:00 by ojimenez          #+#    #+#             */
/*   Updated: 2024/07/18 11:30:00 by ojimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include "ASpell.hpp"

class ASpell;

class ATarget
{
	protected:
		std::string type;

	public:
		ATarget();
		ATarget(std::string type);
		ATarget(const ATarget &cpy);
		ATarget &operator=(const ATarget &cpy);
		virtual ~ATarget();

		virtual ATarget *clone() const = 0;
		const std::string &getType() const;

		void getHitBySpell(const ASpell &spell) const;
};