#include "sort.h"

/**
* selection_sort - orts an array of integers in ascending order
* @array: array of integers
* @size: size of the array
* Return: nothing
*/
void selection_sort(int *array, size_t size)
{
	int temp;
	size_t i, j, index;

	for (i = 0; i < size - 1; i++)
	{
		index = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[index])
				index = j;
		}
		temp = array[i];
		array[i] = array[index];
		array[index] = temp;

		print_array(array, size);
	}
}
