/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojimenez <ojimenez@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 10:42:47 by ojimenez          #+#    #+#             */
/*   Updated: 2024/07/18 10:42:47 by ojimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Warlock.hpp"

int main(void)
{
	Warlock const uri("Uri", "programador");
	uri.introduce();
	std::cout << uri.getName() << " i " << uri.getTitle() << std::endl;
}