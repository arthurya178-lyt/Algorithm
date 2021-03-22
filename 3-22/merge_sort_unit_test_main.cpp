#include "catch.hpp"
#include "MergeSort.h"
#include <vector>

void merge_sort(std::vector<int> & A, size_t p, size_t r);

TEST_CASE("merge sort are computed", "[merge_sort]") {
	std::vector<int> values  = { 3, 5, 1, 4, 2 };
	std::vector<int> result1 = { 1, 2, 3, 4, 5 };
	std::vector<int> result2 = { 1, 3, 2, 4, 5 };
	merge_sort(values, 0, values.size() - 1);
	REQUIRE(values == result1);
	REQUIRE(values == result2);
}
