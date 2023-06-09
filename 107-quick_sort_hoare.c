#include "sort.h"
#include <stdio.h>

#define PRINT_AFTER_SWAP	1

/**
 * partition - implement the Hoare partition scheme for quicksort
 * @array: The array to be partitioned
 * @size: The length of the array
 * @beg: The start index of the section to be partitioned
 * @end: The end index (inclusive) of the section to be partitioned
 *
 * Return: Split index of the array
 */
static inline size_t partition(
		int *array, size_t size, size_t beg, size_t end)
{
	size_t i, piv;	/* Counter to move from right leftwards */
	int temp;

	for (i = end, piv = end; ;)	/* loop forever */
	{
		/* Get first element from left bigger than pivot */
		for (; ((beg <= end) && (array[beg] <= array[piv])); beg++)
		;
		/* Get first element from right equaling/smaller than pivot */
		for (; ((i > beg) && (array[i] > array[piv])); i--)
		;
		/* Swap as long as counters haven't crossed */
		if (beg < i)
		{
			temp = array[i];
			array[i] = array[beg];
			array[beg] = temp;
			#if PRINT_AFTER_SWAP
			print_array(array, size);
			#endif
			if (piv == i)
				piv = beg;
		}
		else
		{
			if ((--beg) != piv)
			{
				temp = array[beg];
				array[beg] = array[piv];
				array[piv] = temp;
				#if PRINT_AFTER_SWAP
				print_array(array, size);
				#endif
				return (beg);
			}
			return (piv);
		}
	}
}

/**
 * partitioned_quick_sort - sorts an section of an array of integers in
 *  ascending order using the partition-exchange sort / quick-sort algorithm
 * @array: The array to be sorted
 * @size: The length of the array
 * @beg: The start index of the section to be sorted
 * @end: The end index (inclusive) of the section to be sorted
 *
 * Return: None
 */
static void partitioned_quick_sort(
		int *array, size_t size, size_t beg, size_t end)
{
	size_t pivot;

	if ((beg >= end) || (size < 2))
		return;
	pivot = partition(array, size, beg, end);

	if (pivot > 0)
		partitioned_quick_sort(array, size, beg, pivot - 1);
	partitioned_quick_sort(array, size, pivot + 1, end);
}

/**
 * quick_sort_hoare - sorts an array of integers in ascending order using the
 *  partition-exchange sort / quick-sort algorithm
 * @array: The array to be sorted
 * @size: The length of the array
 *
 * Return: None
 */
void quick_sort_hoare(int *array, size_t size)
{
	partitioned_quick_sort(array, size, 0, size - 1);
}
