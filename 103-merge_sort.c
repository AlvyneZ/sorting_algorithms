#include "sort.h"
#include <stdio.h>

#define PRINT_AFT_MERGE	1

/**
 * merge_sorted - merges two sorted arrays stored contiguously
 * @array: The memory location of the two arrays
 * @size: The length of the array
 * @split: The split index where the second array starts
 *
 * Return: None
 */
static inline void merge_sorted(int *array, size_t size, size_t split)
{
	size_t l, r;
	int *tmp_arr;

	tmp_arr = malloc(size * sizeof(int));
	if (tmp_arr == NULL)
		return;
	for (l = 0, r = 0; ((l < split) && (r < (size - split)));)
	{
		if (array[l] <= array[r + split])
		{
			tmp_arr[l + r] = array[l];
			l++;
		}
		else
		{
			tmp_arr[l + r] = array[r + split];
			r++;
		}
	}
	while (l < split)
	{
		tmp_arr[l + r] = array[l];
		l++;
	}
	while (r < (size - split))
	{
		tmp_arr[l + r] = array[r + split];
		r++;
	}
	for (l = 0; (l < size); l++)
		array[l] = tmp_arr[l];
	free(tmp_arr);
}

/**
 * merge_sort - sorts an array of integers in ascending
 *  order using the Merge sort algorithm
 * @array: The array to be sorted
 * @size: The length of the array
 *
 * Return: None
 */
void merge_sort(int *array, size_t size)
{
	size_t split;

	if ((size <= 1) || (array == NULL))
		return;
	split = size / 2;
	merge_sort(array, split);
	merge_sort(&(array[split]), (size - split));
	#if PRINT_AFT_MERGE
	printf("Merging...\n");
	printf("[left]: ");
	print_array(array, split);
	printf("[right]: ");
	print_array(&(array[split]), (size - split));
	#endif
	merge_sorted(array, size, split);
	#if PRINT_AFT_MERGE
	printf("[Done]: ");
	print_array(array, size);
	#endif
}
