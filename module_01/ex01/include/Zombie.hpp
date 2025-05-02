/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdonnat <chdonnat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 09:40:37 by chdonnat          #+#    #+#             */
/*   Updated: 2025/05/02 11:46:15 by chdonnat         ###   ########.fr       */
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
