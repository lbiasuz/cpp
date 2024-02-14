#ifndef PMERGEME_HPP
#include <vector>
#include <queue>

class PMergeMe {
	public:
		PMergeMe(char **argv);
		PMergeMe(const PMergeMe & pme);
		PMergeMe & operator=(const PMergeMe & pme);
		~PMergeMe(void);
		void insertionSort(std::vector<int> a);
		void insertionSort(std::deque<int> a);
		void sortVector(void);
		void sortDeque(void);
		void display(void);

	private:
		PMergeMe(void);
		char				**argv;
		std::vector<int>	vec;
		std::deque<int>		deq;
};

#endif