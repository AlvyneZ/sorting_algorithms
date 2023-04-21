#include "sort.h"

#define PRINT_COUNT_ARRAY	1

/**
 * counting_sort - sorts an array of non-negative integers in ascending
 *  order using the Coounting sort algorithm
 * @array: The array to be sorted
 * @size: The length of the array
 *
 * Return: None
 */
void counting_sort(int *array, size_t size)
{
	size_t i, j;
	int *cnt_arr, max;

	if ((array == NULL) || (size == 0))
	{
		return;
	}
	max = array[0];
	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	cnt_arr = malloc((++max) * sizeof(int));
	if (cnt_arr == NULL)
	{
		return;
	}
	for (i = 0; i < (size_t)max; i++)	/* Clearing counts */
		cnt_arr[i] = 0;
	for (i = 0; i < size; i++)	/* Counting occurences of each array element */
		cnt_arr[array[i]]++;
	for (i = 1; i < (size_t)max; i++)	/* Getting cumulative sum */
		cnt_arr[i] += cnt_arr[i - 1];
	print_array(cnt_arr, max);
	for (i = 0, j = 0; i < (size_t)max; i++)
		for (; j < (size_t)cnt_arr[i]; j++)
			array[j] = i;
	free(cnt_arr);
}
