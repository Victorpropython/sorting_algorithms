#include "sort.h"

/**
 * swap_ints -  a function to swap two integers in an array.
 * @a: The first integer to be swapped
 * @b: The second integer to be swapped
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
