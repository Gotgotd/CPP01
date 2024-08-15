/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gautier <gautier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 14:55:42 by gautier           #+#    #+#             */
/*   Updated: 2024/08/15 17:41:52 by gautier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name) : _name(name) {

	announce();
}
Zombie::~Zombie(void) {
	
	std::cout << this->_name << " is dead and gone" << std::endl;
}

void Zombie::announce() {

	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

