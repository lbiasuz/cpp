#ifndef PMERGEME_HPP
#include <vector>
#include <queue>

class PMergeMe {
	public:
		PMergeMe(char **argv);
		PMergeMe(const PMergeMe & pme);
		PMergeMe & operator=(const PMergeMe & pme);
		~PMergeMe(void);

		void sortVector(std::vector<int> & a);
		void sortDeque(std::deque<int> & a);

		void display(void);

	private:
		PMergeMe(void);

		void insertionSort(std::vector<int> & a);
		void insertionSort(std::deque<int> & a);
		void merge(std::vector<int> & a, std::vector<int> & b, std::vector<int> & v);
		void merge(std::deque<int> & a, std::deque<int> & b, std::deque<int> & v);

		char				**argv;
		std::vector<int>	vec;
		std::vector<int>	svec;
		std::deque<int>		deq;
		std::deque<int>		sdeq;
};

#endif