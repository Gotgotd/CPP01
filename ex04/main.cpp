/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdaignea <gdaignea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 15:53:09 by gdaignea          #+#    #+#             */
/*   Updated: 2024/08/20 15:15:06 by gdaignea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <fstream>

void	replace_line(std::string& oldStr, std::string& newStr, std::string& line) {

	size_t	pos = 0;

	pos = line.find(oldStr);
	while (pos != std::string::npos) {
		if (pos == std::string::npos) {
			std::cout << "string '" << oldStr << "' couldn't be found in the file" << std::endl;
			return;
		}
		else {
			line.erase(pos, oldStr.length());
			line.insert(pos, newStr);
		}
		pos = line.find(oldStr);
	}
}

int	main(int ac, const char **av) {

	if (ac != 4) {
		std::cerr << "program must be runned with 3 arguments (in that order) :\n"
			<< "- a file\n"
			<< "- a sentence to be replaced\n"
			<< "- a sentance to replace the 1st one" << std::endl;
		return 1;
	}
	
	std::string		line;
	std::string		file = av[1];
	std::string		newFile = file + ".replace";
	std::string		oldStr = av[2];
	std::string		newStr = av[3];


	std::ifstream	test(av[1]);
	std::ofstream	testCpy(newFile.c_str());

	if (!test.is_open()) {
		std::cerr << "file " << av[1] << "could not be open" << std::endl;
		return 1;
	}

	while (std::getline(test, line)) {
		replace_line(oldStr, newStr, line);
		testCpy << line << std::endl;
	}
	test.close();
	testCpy.close();
	return 0;
}