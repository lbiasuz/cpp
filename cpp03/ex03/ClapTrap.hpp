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

	public:
		ClapTrap(void);
		ClapTrap(std::string name);
		ClapTrap(std::string name, int life, int stamina, int damage);
		ClapTrap(const ClapTrap &copy);
		~ClapTrap(void);
		ClapTrap&	operator=(const ClapTrap &copy);

		virtual void	attack(std::string const & target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
};

#endif