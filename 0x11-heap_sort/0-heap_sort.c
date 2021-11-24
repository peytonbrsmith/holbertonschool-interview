#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * heapify - converts array into heap
 * @arr: array to be converted
 * @n: size of array
 * @i: index of current node
 *
 * Return: void
 */
void heapify(int *arr, int n, int i)
{
	int largest = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;
	int swap;

	if (l < n && arr[l] > arr[largest])
		largest = l;

	if (r < n && arr[r] > arr[largest])
		largest = r;

	if (largest != i)
	{
		swap = arr[i];
		arr[i] = arr[largest];
		arr[largest] = swap;

		print_array(arr, (size_t)n);

		heapify(arr, n, largest);
	}
}

/**
 * heap_sort - heap sorts an array
 * @array: array to be converted
 * @size: size of array
 *
 * Return: void
 */
void heap_sort(int *array, size_t size)
{
	int n = (int)size;
	int temp;

	for (int i = n / 2 - 1; i >= 0; i--)
	{
		heapify(array, n, i);
	}

	for (int i = n - 1; i > 0; i--)
	{

		temp = array[0];
		array[0] = array[i];
		array[i] = temp;

		heapify(array, i, 0);

		if (i > 0)
			print_array(array, size);
	}
}
