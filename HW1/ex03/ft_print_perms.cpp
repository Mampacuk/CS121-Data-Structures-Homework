#include "perms.hpp"

void	ft_output_character(int val)
{
	if (val == a)
		std::cout << "a";
	else if (val == b)
		std::cout << "b";
	else if (val == c)
		std::cout << "c";
	else if (val == d)
		std::cout << "d";
	else if (val == e)
		std::cout << "e";
}

int	ft_isvowel(int val)
{
	return (val == a || val == b);
}

void	ft_print_next_character(int depth, int selected, int vowel, int consonant)
{
	if (depth <= 0 || vowel > e || consonant > d)
		return ;
	if (ft_isvowel(selected))
	{
		ft_output_character(selected); // PRINTED a
		selected = consonant; //b
		ft_print_next_character(depth - 1, selected, vowel, consonant + 1);
		//ft_print_next_character(2, b, a, d);
		//b
		//b = a;
		//PRINTED b
		//ft_print_next_character(1, a, e, d);
		//PRINTED e
		//ft_print_next_character(0, d, e, d+1);



		//abe
	}
	else
	{
		ft_output_character(selected);
		selected = vowel;
		ft_print_next_character(depth - 1, selected, vowel + 1, consonant);
	}
}

void	ft_print_perms(int n)
{
	ft_print_next_character(n, a, a, b);
	std::cout << std::endl;
	ft_print_next_character(n, b, a, b);
	std::cout << std::endl;
	ft_print_next_character(n, c, a, b);
	std::cout << std::endl;
	ft_print_next_character(n, d, a, b);
	std::cout << std::endl;
	ft_print_next_character(n, e, a, b);
	std::cout << std::endl;
}