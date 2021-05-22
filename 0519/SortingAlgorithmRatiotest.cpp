#include <iostream>
#include <algorithm>
#include <random>
#include <cmath>
#include <chrono>
#include <vector>
#include <ctime>
#include "matplotlibcpp.h"
#include "algorithm.h"
namespace plt = matplotlibcpp;
using namespace std;

template<typename T>
void convertToRatioData(vector<T> &tn, vector<T> &Tn)
{
	for (int i = 0; i < tn.size(); i++)
	{
		tn[i] /= Tn[i];
	}
}

void generate_sequential_data(vector<int>& v, int n)
{
	auto f = []() -> int {static int i = 0; return ++i; };
	v.resize(n);
	generate(v.begin(), v.end(), f);
}

void generate_random_data(vector<int>& v, int n)
{
	v.resize(n);
	auto f = [n]() -> int { return rand() % n; };
	generate(v.begin(), v.end(), f);
}

void time_log(const string name, const vector<double>& x, const vector<double>& y)
{
	cout << name << ":" << endl;
	for (int i = 0; i < x.size(); i++) {
		cout << "Size:" << setw(7) << (int)x[i] << " Time:" << fixed << setprecision(7) << y[i] << endl;
	}
	cout << endl;
}

void time_count(void(*fun)(vector<int>&), const vector<double> data_size, vector<double>& running_time)
{
	chrono::high_resolution_clock::time_point start, end;
	vector<int> A;

	for (int i = 0; i < data_size.size(); i++) {
		// 產生資料
		generate_random_data(A, data_size[i]);
		// 開始計時
		start = chrono::high_resolution_clock::now();
		fun(A);
		end = chrono::high_resolution_clock::now();
		// 結束計時
		chrono::duration<double> diff = end - start;
		running_time.push_back(diff.count());
	}

}





int main()
{
	vector<double> dataSize,nLogN;
	for (int i = 1; i <= 100; i++)
	{
		dataSize.push_back(i * 10000);
		nLogN.push_back(i*log2(i));
	}
	
	vector<double> result1, result2, result3;
	time_count(quickSort,dataSize,result1);
	time_log("quickSort", dataSize, result1);

	time_count(std_heapSort,dataSize,result2);
	time_log("std_heapSort",dataSize,result2);

	time_count(std_sort, dataSize, result3);
	time_log("std_sort", dataSize, result3);

	convertToRatioData(result1, nLogN);
	convertToRatioData(result2, nLogN);
	convertToRatioData(result3, nLogN);

	plt::named_plot("quickSort vs. $\\Theta(n*lg(n))$",dataSize,result1);
	plt::named_plot("std_heapSort vs. $\\Theta(n*lg(n))$", dataSize, result2);
	plt::named_plot("std_sort vs.$\\Theta(n*lg(n))$", dataSize, result3);


	plt::title("Sorting Algorithm Ratio Test");
	plt::xlabel("Data Size");
	plt::ylabel("Ratio");
	plt::legend();
	plt::pause(1);
	plt::show();
}
