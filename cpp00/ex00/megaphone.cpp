#include <iostream>
#include <string>

int	main(int argc, char **argv) {
	for (int i = 1; i < argc; i++)
	{
		for (int s = 0; argv[i][s]; s++)
			std::cout << (char) std::toupper(argv[i][s]);
	}
	if (argc < 2)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	std::cout << std::endl;
	return (0);
}