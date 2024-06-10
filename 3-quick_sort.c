#include "sort.h"

void swap_ints(int *a, int *b);
int lomuto_partition(int *array, size_t size, int left, int right);
void lomuto_sort(int *array, size_t size, int left, int right);
void quick_sort(int *array, size_t size);

/**
 * swap_ints - a function to swap two integers in an array
 * @a: First for swapping
 * @b: Second digit for swapping
 * REturn: Nothing
 */
void swap_ints(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}


/**
 * lomuto_partition - Ordering of subset of an integer array and using the
 * the last element of the functionas pivot
 * @array:The array namefor integers
 * @size: of array
 * @left: The first index of the subset to order
 * @right: The last index of the subset
 *
 * Return: The final partirion index, result
 */

int lomuto_partition(int *array, size_t size, int left, int right)
{
	int *pivot, above, below;

	pivot = array + right;
	for (above = below = left; below < right; below++)
	{
		if (array[below] < *pivot)
		{
			if (above < below)
			{
				swap_ints(array + below, array + above);
				print_array(array, size);
			}
			above++;
		}
	}
	if (array[above] > *pivot)
	{
		swap_ints(array + above, pivot);
		print_array(array, size);
	}
	return (above);
}

/**
 * lomuto_sort - Perform the quicksort algorithm through recursion
 * @array: An array of integers to be sorted
 * @size: Array size
 * @left: The first index of the array partition to order
 * @right: The last index of the array partition to order
 */

void lomuto_sort(int *array, size_t size, int left, int right)
{
	int part;

	if (right - left > 0)
	{
		part = lomuto_partition(array, size, left, right);
		lomuto_sort(array, size, left, part - 1);
		lomuto_sort(array, size, part + 1, right);
	}
}

/**
 * quick_sort - Quicksort algorithm function to sort an array
 * of integers in ascending order
 * @array: An array of integers to sort
 * @size: Array size
 *
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}
