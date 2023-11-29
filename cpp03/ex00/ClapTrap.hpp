#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <string>

class ClapTrap {

	private:
		std::string	name;
		int			hitPoints;
		int			energyPoints;
		int			attackDamage;

		int	isAlive(void);

	public:
		ClapTrap(void);
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap &copy);
		~ClapTrap(void);
		ClapTrap&	operator=(const ClapTrap &copy);

		void	attack(std::string const & target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
};

#endif