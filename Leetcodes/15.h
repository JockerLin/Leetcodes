/*
 * author:	Lin Cunqin
 * version:	1.0
 * date:	2020.09.05
 * copyright:	Copyright 2020, Blazar
 * description: xxx
*/

#include <iostream>
#include <vector>

using namespace std;

namespace p15 {
	class Solution {
	public:
		vector<vector<int>> threeSum(vector<int>& nums) {
			vector<vector<int>> vec;

		}
	};
}

void validation15() {
	// 3数和==0的所有不重复组合
	vector<int> input_vec = { -1, 0, 1, 2, -1, -4 };
	vector<vector<int>> output_vec;
	using namespace p15;
	Solution sol;
	output_vec = sol.threeSum(input_vec);
	cout << "input:" << endl;

}