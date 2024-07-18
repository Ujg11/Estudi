/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Warlock.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojimenez <ojimenez@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 09:51:03 by ojimenez          #+#    #+#             */
/*   Updated: 2024/07/18 09:51:03 by ojimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>

class Warlock
{
	private:
		std::string name;
		std::string title;

		Warlock();
		Warlock(const Warlock &cpy);
		Warlock &operator=(const Warlock &cpy);

	public:
		Warlock(std::string name, std::string title);
		~Warlock();

		const std::string &getName() const;
		const std::string &getTitle() const;
		void setTitle(std::string const &title);
		void introduce() const;
};
