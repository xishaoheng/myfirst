#include <vector>

// check is equals to ref , reutrn 1, diff  return 0
int diff_vec(std::vector<int>check, std::vector<int>ref) {
	if (check.size() != ref.size())
		return -1;
	long ans = 0;
	long index_check = 0;
	for (auto i : ref) {
		ans += (i - ref[index_check])*(i - ref[index_check]);
		if (ans != 0)
			return ans;
		index_check++;
	}
	return 0;
}
//default: from small to big
void q_sort_v1(std::vector<int> &data, int left, int right) {
	if (left > right) {
		return;
	}
	int i = left;
	int j = right;
	int tmp = 0;
	int ref = data[(left + right) >> 1];
	while (i <= j) {
		while (data[i] < ref && i < right) i++;
		while (data[j] > ref && j > left) j--;
		if (i <= j) {
			tmp = data[i];
			data[i] = data[j];
			data[j] = tmp;
			i++;
			j--;
		}
	}

	if (j > left)
		q_sort_v1(data, left, j);
	if (i < right)
		q_sort_v1(data, i, right);
}
void q_sort_v2(std::vector<int> &data, int left, int right) {
	if (left > right)	return;
	int i = left;
	int j = right;
	int base = data[(left + right) >> 1];
	int tmp = 0;
	while (i < j)
	{
		while (data[j] >= base && i < j)	j--;
		while (data[i] <= base && i < j)	i++;
		if (i < j) {
			tmp = data[i];
			data[i] = data[j];
			data[j] = tmp;
		}
	}
	data[left] = data[i];
	data[i] = base;
	q_sort_v2(data, left, i - 1);
	q_sort_v2(data, i + 1, right);
}
void heap_sort(std::vector<int> &data, int root, int len) {
	int L_child = root * 2 + 1;
	int R_child = L_child + 1;
	int largest;
	if (L_child < len) {
		//TODO:   if ()
	}
}
void bubble_sort(std::vector<int> &data, int num) {
	int i, j, tmp;
	bool exchange;
	for (i = 0; i < num - 1; i++) {
		exchange = false;
		for (j = 0; j < num - i - 1; j++) {
			if (data[j] > data[j + 1]) {
				//swap
				tmp = data[j];
				data[j] = data[j + 1];
				data[j + 1] = tmp;
				exchange = true;
			}
		}
		if (exchange == false) {
			return;
		}
	}
}
inline void my_swap(int &a, int &b) {
	a |= b;
	b = a | b;
	a |= b;
}