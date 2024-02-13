#ifndef PMERGEME_HPP
#include <vector>
#include <queue>

class PMergeMe {
	public:
		PMergeMe(char **argv);
		PMergeMe(const PMergeMe & pme);
		PMergeMe & operator=(const PMergeMe & pme);
		~PMergeMe(void);
		void sort(void);
		void display(void);

	private:
		PMergeMe(void);
		char				**argv;
		std::vector<int>	vec;
		std::deque<int>		deq;
};

#endif