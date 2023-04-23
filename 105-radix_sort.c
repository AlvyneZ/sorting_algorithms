#include "sort.h"

#define PRINT_AFT_SIG_CHNG	1

/**
 * radix_sort_rec - sorts an array of non-negative integers in ascending
 *  order using the Radix sort algorithm using a specified base given the
 *  significant figure to start from
 * @array: The array to be sorted
 * @size: The length of the array
 * @place: The significant figure place to start sorting from
 * @base: The radix base to be used
 *
 * Return: None
 */
static void radix_sort_rec(int *array, size_t size, int place, int base)
{
	size_t i, j;
	int *tmp_arr, *cpy_arr, c;

	for (i = 0; i < size; i++)
		if (array[i] >= place)
			break;
	if (i >= size)
		return;
	tmp_arr = malloc(size * sizeof(int));
	if (tmp_arr == NULL)
		return;
	cpy_arr = malloc(size * sizeof(int));
	if (cpy_arr == NULL)
	{
		free(tmp_arr);
		return;
	}
	for (i = 0; i < size; i++)
	{
		tmp_arr[i] = (array[i] / place) % base;
		cpy_arr[i] = array[i];
	}
	for (i = 0, c = 0; c < base; c++)
		for (j = 0; j < size; j++)
			if (tmp_arr[j] == c)
				array[i++] = cpy_arr[j];
	free(tmp_arr);
	free(cpy_arr);
	#if PRINT_AFT_SIG_CHNG
	print_array(array, size);
	#endif
	radix_sort_rec(array, size, (place * base), base);
}

/**
 * radix_sort - sorts an array of non-negative integers in ascending
 *  order using the Radix sort algorithm (base 10)
 * @array: The array to be sorted
 * @size: The length of the array
 *
 * Return: None
 */
void radix_sort(int *array, size_t size)
{
	if ((size <= 1) || (array == NULL))
		return;
	radix_sort_rec(array, size, 1, 10);
}
