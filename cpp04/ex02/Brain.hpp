#ifndef BRAIN_HPP
# define BRAIN_HPP
# include <string>

class Brain {
	private:
		std::string ideas[100];
	
	public:
		Brain(void);
		Brain(const Brain & old);
		~Brain(void);
		Brain& operator=(const Brain & old);

		void newIdea(std::string str);
		std::string getIdea(int i) const;
};

#endif