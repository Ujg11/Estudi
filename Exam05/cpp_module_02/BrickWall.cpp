/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BrickWall.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojimenez <ojimenez@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 16:15:57 by ojimenez          #+#    #+#             */
/*   Updated: 2024/07/18 16:15:57 by ojimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BrickWall.hpp"

BrickWall::BrickWall()
{
	this->type = "Inconspicuous Red-brick Wall";
}

BrickWall::~BrickWall()
{
}

ATarget *BrickWall::clone() const
{
	return (new BrickWall());
}