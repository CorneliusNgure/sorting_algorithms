#include <stdio.h>
#include "sort.h"

/**
 * shell_sort - Sorts an array of integers in ascending order using Shell sort
 * algorithm with Knuth sequence
 * @array: Array to be sorted
 * @size: Size of the array
 */
void shell_sort(int *array, size_t size)
{
	size_t interval = 1, i, j;
	int temp;

	if (array == NULL || size < 2)
		return;

	while (interval < size / 3)
		interval = interval * 3 + 1;

	while (interval > 0)
	{
		for (i = interval; i < size; i++)
		{
			temp = array[i];
			j = i;

			while (j >= interval && array[j - interval] > temp)
			{
				array[j] = array[j - interval];
				j -= interval;
			}

			array[j] = temp;
		}

		print_array(array, size);
		interval = (interval - 1) / 3;
	}
}
