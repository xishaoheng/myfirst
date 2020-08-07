// ALG_sorts.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>
#include "sort_core.h"
int main()
{
	const int NN = 10000;
	std::vector<int> data(NN, 0);
	srand((unsigned)time(0));
	long id = 0;
	int start = -2020, end = 2020;
	float tmp_d = 0.f;
	std::vector<int> test = { 1, 8, 9, 12, 7, 2, 0 };
	
	for (auto &i : data) {
		tmp_d = (end - start) * rand() / (RAND_MAX + 1.f);
		i += start + static_cast<int>(tmp_d);
		//std::cout << "[" << id++ << "]" << ":" << i << std::endl;
	}
	std::vector<int> data_1(data);
	std::vector<int> data_2(data);
	
	clock_t bg = clock();
	std::sort(data.begin(), data.end(), cmp<int>);
	double use_STL_sort = static_cast<double>(clock()-bg);
	int len = data_2.size();

	//q_sort_v1(test, 0, 6);
	bg = clock();
	q_sort_v1(data_1, 0, NN - 1);
	double use_qsort_1 = static_cast<double>(clock()-bg);
	
	bg = clock();
	q_sort_v2(data_2, 0, NN - 1);
	double use_qsort_2 = static_cast<double>(clock()-bg);
	
	/*
	id = 0;
	for (auto &i : test) {
		std::cout << "[" << id++ << "]" << ":" << i << std::endl;
	}
	*/
	bubble_sort(test, 7);
	int ans2 = diff_vec(data_2, data);
	int ans1 = diff_vec(data_1, data);
	std::cout << "diff_1 is " << ans1 << std::endl;
	std::cout << "diff_2 is " << ans2 << std::endl;
	std::cout << "STL_sort cost_t is " << use_STL_sort << std::endl;
	std::cout << "qsort_v1 cost is " << use_qsort_1 << std::endl;
	std::cout << "qsort_v2 cost is " << use_qsort_2 << std::endl;
    std::cout << "Hello World!\n";
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
