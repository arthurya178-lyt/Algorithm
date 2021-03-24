#include <algorithm>
#include "algorithm.h"
void swap(int &var1 , int &var2)
{
	int a = var1;
	var1 = var2;
	var2 = a;
}

void insertion_sort(vector<int>& A)
{
	for (int i = 1; i < A.size(); i++)
	{
		int locate = i;
		while (locate - 1 >= 0 && A[locate] < A[locate - 1])
		{
			swap(A[locate], A[locate - 1]);
			locate--;
		}
	}
} // end of insertion_sort



void selection_sort(vector<int>& A)
{
	for (int i = 0; i < A.size() - 1; i++)
	{
		int small = INT_MAX, index;
		for (int j = i; j < A.size(); j++)
		{
			if (A[j] < small)
			{
				small = A[j];
				index = j;
			}
		}
		swap(A[i], A[index]);
	}

} // end of selection_sort

void bubble_sort(vector<int>& A)
{
	for (int i = A.size()-1; i > 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			if (A[j] > A[j + 1])
			{
				swap(A[j], A[j + 1]);
			}
		}
	}
}

int linear_search(vector<int>& A, int v)
{
	for (int i = 0; i < A.size(); i++)
	{
		if (A[i] == v)
			return i;
	}
	return -1;
} // end of linear_search

//======================以下使用STL的函式======================

bool mypredicate(int i, int j)
{
	return (i == j);
}

int std_search_default(vector<int>& A, int v)
{
	vector<int> B = { v };
	vector<int>::iterator it;
	it = std::search(A.begin(), A.end(), B.begin(), B.end());

	if (it != A.end())
		return it - A.begin();
	else
		return -1;
}

int std_search_predicate(vector<int>& A, int v)
{
	vector<int> B = { v };
	vector<int>::iterator it;
	it = std::search(A.begin(), A.end(), B.begin(), B.end(), mypredicate);

	if (it != A.end())
		return it - A.begin();
	else
		return -1;
}

int std_find(vector<int>& A, int v) {
	vector<int>::iterator it;
	it = std::find(A.begin(), A.end(), v);

	if (it != A.end())
		return it - A.begin();
	else
		return -1;
}
