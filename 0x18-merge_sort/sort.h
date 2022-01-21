#ifndef _SORT_H_
#define _SORT_H_

#include <stdio.h>
#include <stdlib.h>

void SplitMerge(int B[], int iBegin, int iEnd, int A[]);
void Merge(int A[], int iBegin, int iMiddle, int iEnd, int B[]);
void CopyArray(int A[], int iBegin, int iEnd, int B[]);
void merge_sort(int *array, size_t size);
void print_array(const int *array, size_t size);

#endif
