#include "perms.hpp"

int	main(void)
{
	int	n;

	std::cout << "Enter the N to be passed to ft_print_perms(): ";
	std::cin >> n;
	if (std::cin.fail() || n < 0)
	{
		std::cout << "Invalid input" << std::endl;
		return (1);
	}
	ft_print_perms(n);
}