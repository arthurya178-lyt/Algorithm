#include "MergeSort.h"

void merge(vector<int> &arr, size_t f, size_t m, size_t e)
{
	vector<int> left, right;
	for (int i = f; i <= m; i++)
		left.push_back(arr[i]);
	left.push_back(INT_MAX);
	for (int i = m+1; i <= e; i++)
		right.push_back(arr[i]);
	right.push_back(INT_MAX);
	int leftIndex = 0, rightIndex = 0;
	for (int i = f; i <= e;i++)
	{
		if (left[leftIndex] < right[rightIndex])
		{
			arr[i] = left[leftIndex];
			leftIndex++;
		}
		else
		{
			arr[i] = right[rightIndex];
			rightIndex++;
		}
	}
}

void merge_sort(vector<int> & A, size_t p, size_t r)
{
	if (p < r)
	{
		int q = (p + r) / 2;
		merge_sort(A,p,q);
		merge_sort(A,q+1,r);
		merge(A, p, q, r);
	}
}
