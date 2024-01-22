#include "sort.h"
#include <stdio.h>

/**
 * shell_sort - sorts an array of integers in ascending order
 * @array: array
 * @size: size of array
 */

void shell_sort(int *array, size_t size)
{
	int temp;
	unsigned int interval, i, j;

	if (!array ||	size < 2)
		return;

	for (interval = 1; interval <= size / 3; interval = interval * 3 + 1)
		;

	while (interval > 0)
	{
		print_array(array, size);

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

		interval = (interval - 1) / 3;
	}

	print_array(array, size);
}
