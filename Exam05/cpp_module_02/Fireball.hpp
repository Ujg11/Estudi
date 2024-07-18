/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fireball.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojimenez <ojimenez@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 15:47:22 by ojimenez          #+#    #+#             */
/*   Updated: 2024/07/18 15:47:22 by ojimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include "ASpell.hpp"

class Fireball: public ASpell
{
	public:
		Fireball();
		~Fireball();
	
		ASpell *clone() const;
};
