#ifndef ALGORITHM_H
#define ALGORITHM_H

#include <vector>
using namespace std;

void insertion_sort(vector<int>&);
void selection_sort(vector<int>&);
void bubble_sort(vector<int>&);
int linear_search(vector<int>&, int);
int std_search_default(vector<int>&, int);
int std_search_predicate(vector<int>&, int);
int std_find(vector<int>&, int);
#endif

