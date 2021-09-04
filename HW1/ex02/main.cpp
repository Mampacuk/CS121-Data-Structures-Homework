#include <iostream>

int	ft_count_palindromes(int *arr, int arr_size, int low, int high);

int	main(void)
{
	int	size;
	int	*arr;

	std::cout << "Enter the length of the array: ";
	std::cin >> size;
	if (std::cin.fail() || size <= 0)
	{
		std::cout << "Invalid input" << std::endl;
		exit(1);
	}
	arr = new int(size);
	for (int i = 0; i < size; i++)
	{
		std::cout << "Input number " << i << ": ";
		std::cin >> arr[i];
		if (std::cin.fail())
		{
			std::cout << "Invalid input" << std::endl;
			exit(1);
		}
	}
	std::cout << "Number of palindromes: "
		<< ft_count_palindromes(arr, size, 0, size - 1) << std::endl;
	delete arr;
}