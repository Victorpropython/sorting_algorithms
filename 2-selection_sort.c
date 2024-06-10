#include "sort.h"
/**
 * swap_ints - afunction to swap integers in an array
 * @a: First integer to be swapped
 * @b: The second integer to be swapped
 */

void swap_ints(ints *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * selection_sort - selection sort algorithm to sort array of
 * of integers in ascending order
 * @array: An array of integers
 * @size: Size of array
 *
 */
void selection_sort(int *array, size_t size)
{
	int *min;
	size_t i, j;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min = array + i;
		for (j = i + 1, j < size; j++)
		{
			min = (array[j] < *min) ? (array + j) : min;
		}
		if ((array + i) != min)
		{
			swap_ints(array + i, min);
			print_array(array, size);
		}
	}
}
