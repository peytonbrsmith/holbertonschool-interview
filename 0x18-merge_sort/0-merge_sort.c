#include "sort.h"

/**
 * SplitMerge - split merge function
 *
 * @new_array: array to be sorted
 * @l_start: left start
 * @r_end: right end
 * @array: array to be sorted
 */
void SplitMerge(int new_array[], int l_start, int r_end, int array[])
{
	int mid;

	if (r_end - l_start <= 1)
		return;
	mid = (r_end + l_start) / 2;
	SplitMerge(array, l_start, mid, new_array);
	SplitMerge(array, mid, r_end, new_array);
	Merge(new_array, l_start, mid, r_end, array);
}

/**
 * Merge - main merge function
 *
 * @array: array to be sorted
 * @l_start: left start
 * @mid: mid
 * @r_end: right end
 * @new_array: array to be sorted
 */
void Merge(int array[], int l_start, int mid, int r_end, int new_array[])
{
	int i = l_start, j = mid, k;

	printf("Merging...\n[left]: ");
	while (array && i < mid)
	{
		if (i > l_start)
			printf(", ");
		printf("%d", array[i]);
		++i;
	}
	i = l_start;
	printf("\n");
	printf("[right]: ");
	print_array(array + mid, r_end - mid);
	for (k = l_start; k < r_end; k++)
	{
		if (i < mid && (j >= r_end || array[i] <= array[j]))
		{
			new_array[k] = array[i];
			i = i + 1;
		}
		else
		{
			new_array[k] = array[j];
			j = j + 1;
		}
	}
	printf("[Done]: ");
	i = l_start;
	while (new_array && i < r_end)
	{
		if (i > l_start)
			printf(", ");
		printf("%d", new_array[i]);
		++i;
	}
	printf("\n");
}

/**
 * ArrayCopy - array copy function
 *
 * @array: array to be sorted
 * @l_start: left start
 * @r_end: right end
 * @new_array: array to be sorted
 */
void ArrayCopy(int array[], int l_start, int r_end, int new_array[])
{
	int k;

	for (k = l_start; k < r_end; k++)
		new_array[k] = array[k];
}

/**
 * merge_sort - entry point of merge program
 *
 * @array: array to be sorted
 * @size: size of array
 */
void merge_sort(int *array, size_t size)
{
	int *new_array = malloc(size * sizeof(int));

	if (new_array == NULL)
		return;

	ArrayCopy(array, 0, size, new_array);
	SplitMerge(new_array, 0, size, array);
	free(new_array);
}
