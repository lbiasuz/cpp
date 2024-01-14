#include "iter.hpp"
#include <string>

int main(void) {
	std::string arr[] = {"abacate", "banana", "bergamota"};
	iter(arr, 3, prnt);
}