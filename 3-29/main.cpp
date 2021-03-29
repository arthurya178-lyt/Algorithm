#include <iostream>
#include <algorithm>
#include "algorithm.h"
#include <iomanip>
#include <vector>
#include <chrono>
#include <cmath>
#include "matplotlibcpp.h"

namespace plt = matplotlibcpp;
using namespace std;

void Pn(vector<double> &arr, vector<double> &res,int d)
{
	
	for (int i = 0; i < arr.size(); i++)
	{
		double total = 0;
		for (int j = 0; j <= d; j++)
		{
			total += pow(arr[i], j);
		}
		res.push_back(total);
	}
}

void ThetaN(vector<double> &arr, vector<double> &res, double d)
{
	for (int i = 0; i < arr.size(); i++)
	{
		res.push_back(pow(arr[i], d));
	}
}

void OmegaN(vector<double> &arr, vector<double> &res, double d)
{
	for (int i = 0; i < arr.size(); i++)
	{
		res.push_back(pow(arr[i], d));
	}
}

void ON(vector<double> &arr, vector<double> &res, double d)
{
	for (int i = 0; i < arr.size(); i++)
	{
		res.push_back(pow(arr[i], d));
	}
}

int main()
{
	//std::cout << "Hello World!\n";
	vector<double> data_size;
	for (int i = 10; i <= 100; i++) {  
		data_size.push_back(i);
	}
	vector<double> result1, result2, result3, result4;
	Pn(data_size, result1,2);
	ThetaN(data_size, result2, 2);
	ON(data_size, result3, 1.975);
	OmegaN(data_size, result4, 2.025);

	plt::figure_size(1200, 780);
	plt::named_plot("P(n)", data_size, result1);
	plt::named_plot("Theta(n)", data_size, result2,":");
	plt::named_plot("o(n)", data_size, result3,"--");
	plt::named_plot("Omega(n)", data_size, result4,"-.");
	plt::title("Comparison");
	plt::legend();
	plt::pause(1);//最好加上該句，否則有時候顯示不了圖像，或者圖像顯示很慢
	plt::show();

}
