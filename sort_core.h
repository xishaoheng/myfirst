#pragma once
#include <vector>
#ifndef _SORT_CORE_
#define _SORT_CORE_
template <class T>
inline bool cmp(T a, T b) {
	return a < b;
}
int diff_vec(std::vector<int>check, std::vector<int>ref);

void q_sort_v1(std::vector<int> &data, int left, int right);

void q_sort_v2(std::vector<int> &data, int left, int right);

void bubble_sort(std::vector<int> &data, int num);

#endif //

