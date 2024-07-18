/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dummy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojimenez <ojimenez@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 11:56:51 by ojimenez          #+#    #+#             */
/*   Updated: 2024/07/18 11:56:51 by ojimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include "ATarget.hpp"

class Dummy: public ATarget
{
	public:
		Dummy();
		~Dummy();

		ATarget *clone() const;
};