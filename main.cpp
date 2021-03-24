#include <iostream>
#include <algorithm>
#include "algorithm.h"
#include <iomanip>
#include <vector>
#include <chrono>
#include "matplotlibcpp.h"

namespace plt = matplotlibcpp;
using namespace std;

void generate_random_data(std::vector<int>& v, int size)
{
	v.resize(size);
	/*
	auto f = [size]() -> int { return rand() % size; };
	generate(v.begin(), v.end(), f);
	*/

	for (int i = 0; i < v.size(); i++) {
		v[i] = rand() % size;
	}
}


void time_count(int(*fun)(vector<int>&, int), const vector<double> data_size, vector<double>& running_time)
{
	chrono::high_resolution_clock::time_point start, end;
	vector<int> A;
	int v;

	for (int i = 0; i < data_size.size(); i++) {
		// 產生資料
		generate_random_data(A, data_size[i]);
		v = -1;
		// 開始計時
		start = chrono::high_resolution_clock::now();
		fun(A, v);
		end = chrono::high_resolution_clock::now();
		// 結束計時
		chrono::duration<double> diff = end - start;
		running_time.push_back(diff.count());
	}
}

void time_log(const string name, const vector<double>& x, const vector<double>& y) {
	cout << name << ":" << endl;
	for (int i = 0; i < x.size(); i++) {
		cout << "Size:" << setw(6) << (int)x[i] << " Time:" << fixed << setprecision(7) << y[i] << endl;
	}
	cout << endl;
}

int main()
{
	//std::cout << "Hello World!\n";
	vector<double> data_size;
	for (int i = 1; i <= 10; i++) {
		data_size.push_back(i * 10000);
	}
	vector<double> result1, result2, result3, result4;

	time_count(linear_search, data_size, result1);
	time_log("linear_search", data_size, result1);
	time_count(std_search_default, data_size, result2);
	time_log("std_search_default", data_size, result2);
	time_count(std_search_predicate, data_size, result3);
	time_log("std_search_predicate", data_size, result3);
	time_count(std_find, data_size, result4);
	time_log("std_find", data_size, result4);

	plt::figure_size(1200, 780);
	plt::named_plot("linear_search", data_size, result1);
	plt::named_plot("std_search_default", data_size, result2);
	plt::named_plot("std_search_predicate", data_size, result3);
	plt::named_plot("std_find", data_size, result4);
	plt::title("Search Methods Comparison");
	plt::legend();
	plt::pause(1);//最好加上該句，否則有時候顯示不了圖像，或者圖像顯示很慢
	plt::show();

}
