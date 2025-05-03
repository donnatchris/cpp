/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christophedonnat <christophedonnat@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 21:20:42 by christophed       #+#    #+#             */
/*   Updated: 2025/05/03 11:44:05 by christophed      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>
#include <sys/stat.h>

void	exit_error(int mode)
{
	std::cerr << "Error: ";
	if (mode == 0)
		std::cerr << "3 arguments required  " << "(a filename and 2 strings).";
	else if (mode == 1)
		std::cerr << "cannot open file.";
	else if (mode == 2)
		std::cerr << "failed to create replace file.";
	std::cerr << std::endl;
	exit(1);
}

bool is_directory(const char *path)
{
	struct stat s;

	if (stat(path, &s) == 0)
		return (S_ISDIR(s.st_mode));
	return (false);
}

std::string	search_n_replace(std::string line, const std::string& target, const std::string& replacer)
{
	std::size_t	pos = 0;

	while ((pos = line.find(target, pos)) != std::string::npos)
	{
		std::string before = line.substr(0, pos);
		std::string	after = line.substr(pos + target.length());
		line = before + replacer + after;
		pos += replacer.length();
	}
	return (line);
}

int	main(int ac, char **av)
{
	if (ac != 4)
		exit_error(0);
	
	std::ifstream	readStream(av[1]);
	if (!readStream.is_open() || !readStream.good() || is_directory(av[1]))
	{
		readStream.close();
		exit_error(1);
	}
	
	std::string		replaceFile(std::string(av[1]) + ".replace");
	std::ofstream	writeStream(replaceFile.c_str());
	if (!writeStream.is_open() || !writeStream.good())
	{
		readStream.close();
		writeStream.close();
		exit_error(2);
	}

	std::string	target(av[2]), replacer(av[3]), line;
	while (std::getline(readStream, line))
	{
		std::string	newline = search_n_replace(line, target, replacer);
		writeStream << newline << std::endl;
	}
	std::cout << "File " << replaceFile << " has been created." << std::endl;
	
	readStream.close();
	writeStream.close();
	return (0);
}
