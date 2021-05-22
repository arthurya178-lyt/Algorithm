#pragma once
#include <iostream>
#include <algorithm>
#include <random>
#include <cmath>
#include <vector>
#include "Toolbox.h"
using namespace std;
template<typename T>
int partition(vector<T> &arr,int compare,const int front, const int last)
{
	swap(arr[compare], arr[front]);
	int change = front;
	for (int i = front+1; i <= last; i++)
	{
		if (arr[front] > arr[i])
			swap(arr[++change], arr[i]);
	}
	swap(arr[front], arr[change]);
	return change;
}
template<typename T>
void quickSort(vector<T> &arr,int front,int last )
{
	if(front < last)
	{
		int m = partition(arr,front, front, last);
		quickSort(arr,front,m-1);
		quickSort(arr,m+1,last);
	}
}
template<typename T>
void quickSort(vector<T> &arr)
{
	int first = 0, last = arr.size() - 1;
	quickSort(arr, first, last);
}
template <typename T>
void randomizeQuickSort(vector<T> &arr, int front, int last)
{
	if (front < last )
	{
		int target = rand() % (last + 1) + front;
		int m = partition(arr, target, front, last);
		quickSort(arr, front, m - 1);
		quickSort(arr, m + 1, last);
	}
}

template<typename T>
void randomizeQuickSort(vector<T> &arr)
{
	int first = 0, last = arr.size() - 1;
	randomizeQuickSort(arr, first, last);
}

template<typename T>
void std_heapSort(vector<T> &arr)
{
	make_heap(arr.begin(), arr.end());
	sort_heap(arr.begin(), arr.end());
}

template<typename T>
void std_sort(vector<T> &arr)
{
	sort(arr.begin(), arr.end());
}
