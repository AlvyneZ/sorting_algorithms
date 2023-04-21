#include "sort.h"

#define PRINT_AFTER_SWAP	1

/**
 * selection_sort - sorts an array of integers in ascending order using the
 *  Selection sort algorithm
 * @array: The array to be sorted
 * @size: The length of the array
 *
 * Return: None
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, idx;
	int temp;

	if (size <= 1)
		return;
	for (i = 0; i < size - 1; i++)
	{
		idx = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[idx])
			{
				idx = j;
			}
		}
		if (idx != i)
		{
			temp = array[i];
			array[i] = array[idx];
			array[idx] = temp;
			#if PRINT_AFTER_SWAP
			print_array(array, size);
			#endif
		}
	}
}
