/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Polymorph.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojimenez <ojimenez@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 15:47:25 by ojimenez          #+#    #+#             */
/*   Updated: 2024/07/18 15:47:25 by ojimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include "ASpell.hpp"

class Polymorph: public ASpell
{
	public:
		Polymorph();
		~Polymorph();

		ASpell *clone() const;
};