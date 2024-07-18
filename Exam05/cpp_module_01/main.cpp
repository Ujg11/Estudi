/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojimenez <ojimenez@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 15:34:05 by ojimenez          #+#    #+#             */
/*   Updated: 2024/07/18 15:34:05 by ojimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Warlock.hpp"
#include "Dummy.hpp"
#include "Fwoosh.hpp"

int main()
{
	Warlock uri("Uri", "programer");

	Dummy fire;
	Fwoosh *fwoosh = new Fwoosh();

	uri.introduce();
	uri.learnSpell(fwoosh);
	uri.launchSpell("Fwoosh", fire);
	uri.forgetSpell("Fwoosh");
	uri.launchSpell("Fwoosh", fire);
	
	delete fwoosh;
}