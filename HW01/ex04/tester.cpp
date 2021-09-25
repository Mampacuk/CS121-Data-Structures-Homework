#include "../../libft/libft.hpp"

int	main(void)
{
	s_list<int>	*a;

	a = NULL;
	ft_lstadd<int>(&a, 0);
	ft_lstprint(a);
	// std::cout << "______" << std::endl;
	ft_lstadd<int>(&a, 1);
	// std::cout << "______" << std::endl;
	ft_lstadd<int>(&a, 10000);
	// std::cout << "______" << std::endl;
	ft_lstadd<int>(&a, 10001);
	// std::cout << "______" << std::endl;

	// std::cout << "______" << std::endl;
	ft_lstadd<int>(&a, 9999);
	ft_lstadd<int>(&a, 99999999);
	// std::cout << "______" << std::endl;
	// ft_lstprint(a);
	// return (0);
	ft_lsthybrid_sort<int>(&a);
}
