#include "sort.h"

#define PRINT_AFTER_SWAP	1

/**
 * bubble_sort - sorts an array of integers in ascending order using the
 *  Bubble sort algorithm
 * @array: The array to be sorted
 * @size: The length of the array
 *
 * Return: None
 */
void bubble_sort(int *array, size_t size)
{
	size_t i;
	int swapped = 1, temp;

	if (size <= 1)
		return;
	size--;
	while (swapped)
	{
		swapped = 0;
		for (i = 0; i < size; i++)
		{
			if (array[i] > array[i + 1])
			{
				swapped = 1;
				temp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = temp;
				#if PRINT_AFTER_SWAP
				print_array(array, size + 1);
				#endif
			}
		}
	}
}
