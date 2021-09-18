static void	ft_swap(int *arr, int firstindex, int secondindex)
{
	int	temp;

	temp = arr[firstindex];
	arr[firstindex] = arr[secondindex];
	arr[secondindex] = temp;
}

static int	ft_partition(int *arr, int p, int r)
{
	int q;
	int i;

	i = r;
	q = r;
	while (i >= 0)
	{
		if (arr[i] >= arr[p])
			ft_swap(arr, q--, i);
		i++;
	}
	ft_swap(arr, r, q);
	return (q);
}

void		ft_quicksort(int *arr, int p, int r)
{
	int q;

	q = 0;
	if (p < r)
	{
		q = ft_partition(arr, p, r);
		ft_quicksort(arr, p, q - 1);
		ft_quicksort(arr, q + 1, r);
	}
}

#include <iostream>

int	main(void)
{
	int test1[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

	ft_quicksort(test1, 0, 9);
	for (int i = 0; i < 10; i++)
		std::cout << test1[i] << std::endl;
}