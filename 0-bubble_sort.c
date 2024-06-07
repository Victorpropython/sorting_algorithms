#include "sort.h"
/**
 * bubble_sort - function that sorts an array of integers in ascending order
 * @array: pointer to arrary
 * @size: size of array
 * Return: To return integers in ascending order
 */
void bubble_sort(int *array, size_t size)
{
	size_t i;
	bool bubb = false;

	if (array == NULL || size < 2)
	{
		return;
	}
	while (bubb == false)
	{
		bubb = true;
		for (i = 0; i < size - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				swap_ints(array + i, array + i + 1);
				print_array(array, size);
				bubb = false;
			}
		}
		size--;
	}
}
