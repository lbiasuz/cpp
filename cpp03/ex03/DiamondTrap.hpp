#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP
# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap: public ScavTrap, public FragTrap
{
	public:
		DiamondTrap(void);
		DiamondTrap(std::string name);
		DiamondTrap(DiamondTrap const & old);
		~DiamondTrap(void);
		DiamondTrap & operator=(DiamondTrap const & old);

		void	whoAmI(void);

	private:
		std::string	name;
};

#endif