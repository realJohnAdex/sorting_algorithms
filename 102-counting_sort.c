#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * counting_sort - Sorts an array of integers in ascending order using
 *                 Counting sort algorithm
 *
 * @array: The array to be sorted
 * @size: Number of elements in the array
 */
void counting_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	/* Find the maximum element in the array */
	int max = array[0];
	size_t i;
	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	/* Create a counting array with size (max + 1) */
	int *count = malloc((max + 1) * sizeof(int));
	if (count == NULL)
		return;

	/* Initialize counting array with zeros */
	for (i = 0; i <= max; i++)
		count[i] = 0;

	/* Count the occurrences of each element in the array */
	for (i = 0; i < size; i++)
		count[array[i]]++;

	/* Print the counting array */
	printf("Counting array:\n");
	for (i = 0; i <= max; i++)
		printf("%d: %d\n", (int)i, count[i]);

	/* Modify counting array to store the position */
	/* of each element in the output array */
	for (i = 1; i <= max; i++)
		count[i] += count[i - 1];

	/* Create a temporary array to store the sorted output */
	int *output = malloc(size * sizeof(int));
	if (output == NULL)
	{
		free(count);
		return;
	}

	/* Populate the output array using the counting array */
	for (i = 0; i < size; i++)
	{
		output[count[array[i]] - 1] = array[i];
		count[array[i]]--;
	}

	/* Copy the sorted output array to the original array */
	for (i = 0; i < size; i++)
		array[i] = output[i];

	/* Print the sorted array */
	printf("Sorted array:\n");
	print_array(array, size);

	/* Free dynamically allocated memory */
	free(count);
	free(output);
}

