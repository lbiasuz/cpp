#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {

	public:
		ScavTrap(void);
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap &copy);
		~ScavTrap(void);
		ScavTrap&	operator=(const ScavTrap &copy);

		void	guardGate(void);

	private:
		bool	gateKeeping;

};

#endif
