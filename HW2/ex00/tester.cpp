#include "sorting.hpp"

/*
 * This program will take arguments from command line and sort them 
 */
int	main(int, char **argv)
{
	argv++;
	/*
	 * Uncomment this for Selection Sort, and comment the ft_selection_sort() call
	 */
	// ft_selection_sort(argv);
	ft_insertion_sort(argv, argv);
	for (int i = 0; argv[i]; i++)
		std::cout << argv[i] << std::endl;
}
