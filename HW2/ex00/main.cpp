#include "sorting.hpp"

int	main(void)
{
	int		n;
	char	*buf;
	char	**mtx;

	std::cout << "TEST00: SELECTION SORT" << std::endl;
	std::cout << "PLEASE INPUT THE NUMBER OF STRINGS: ";
	std::cin >> n;
	if (std::cin.fail() || n < 1)
	{
		std::cout << "Invalid input" << std::endl;
		return (1);
	}
	mtx = new char *[n + 1];
	for (int i = 0; i < n; i++)
	{
		buf = new char[BUFSIZ];
		std::cin >> buf;
		mtx[i] = strdup(buf);
		delete [] buf;
	}
	mtx[n] = NULL;
	ft_selection_sort(mtx);
	std::cout << "THE RESULT:" << std::endl;
	for (int i = 0; mtx[i]; i++)
	{
		std::cout << mtx[i] << std::endl;
		free(mtx[i]);
	}
	
	std::cout << "TEST01: INSERTION SORT" << std::endl;
	std::cout << "PLEASE INPUT THE NUMBER OF STRINGS: ";
	std::cin >> n;
	if (std::cin.fail() || n < 1)
	{
		std::cout << "Invalid input" << std::endl;
		return (1);
	}
	for (int i = 0; i < n; i++)
	{
		buf = new char[BUFSIZ];
		std::cin >> buf;
		mtx[i] = strdup(buf);
		delete [] buf;
	}
	ft_insertion_sort(mtx, mtx);
	std::cout << "THE RESULT:" << std::endl;
	for (int i = 0; mtx[i]; i++)
	{
		std::cout << mtx[i] << std::endl;
		free(mtx[i]);
	}
}