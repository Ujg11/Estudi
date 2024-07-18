/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fwoosh.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojimenez <ojimenez@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 11:48:23 by ojimenez          #+#    #+#             */
/*   Updated: 2024/07/18 11:48:23 by ojimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include "ASpell.hpp"

class Fwoosh: public ASpell
{
	public:
		Fwoosh();
		~Fwoosh();

		ASpell *clone() const;
};