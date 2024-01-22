#include "sort.h"
#include <stdio.h>

/**
 * shell_sort - sorts an array of integers in ascending order
 * @array: array
 * @size: size of array
 */

void shell_sort(int *array, size_t size)
{
	size_t gap = 1, i, index = 0, temp;

	if (array == NULL || size < 2)
		return;
	while (gap < size / 3)
		gap = 3 * gap + 1;
	while (gap >= 1)
	{
		for (i = gap; i < size; i++)
			for (index = i; index >= gap &&
			 (array[index] < array[index - gap]); index -= gap)
			{
				temp = array[index];
				array[index] = array[index - gap];
				array[index - gap] = temp;
			}
		print_array(array, size);
		gap /= 3;
	}
}
