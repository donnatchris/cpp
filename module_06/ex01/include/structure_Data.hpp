/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure_Data.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christophedonnat <christophedonnat@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 07:54:14 by christophed       #+#    #+#             */
/*   Updated: 2025/05/19 07:57:09 by christophed      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURE_DATA_H
# define STRUCTURE_DATA_H

# include <string>

typedef struct data_s
{
	std::string name;
	int			age;
} Data;

#endif