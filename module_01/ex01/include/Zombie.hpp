/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christophedonnat <christophedonnat@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 09:40:37 by chdonnat          #+#    #+#             */
/*   Updated: 2025/05/07 20:57:21 by christophed      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>

class Zombie {
	public:
    
		Zombie();
		Zombie( std::string name );
		~Zombie();
        
		void    setName( std::string name );
        void    announce( void );

    private:
        
		std::string _name;

};

#endif
