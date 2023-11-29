#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <string>

class ClapTrap {

	protected:
		std::string	name;
		int			hitPoints;
		int			hitPointsMax;
		int			energyPoints;
		int			attackDamage;

		virtual int	isAlive(void);

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