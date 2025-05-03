/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christophedonnat <christophedonnat@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 11:20:29 by christophed       #+#    #+#             */
/*   Updated: 2025/05/03 11:27:51 by christophed      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <string>

class	Harl
{
	public:

		Harl();
		~Harl();

		void	complain( std::string level );

	private:

		void	debug( void );
		void	info( void );
		void	warning( void );
		void	error( void );
};

#endif