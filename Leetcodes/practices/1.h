/*
 * author:	Lin Cunqin
 * version:	1.0
 * date:	2020.10.16
 * copyright:	Copyright 2020, Blazar
 * description: 要求找到所有「不重复」且和为 target 的二元组
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

namespace p1 {
	class Solution {
	public:
		vector<int> twoSum(vector<int>& nums, int target) {
			vector<int> res;
			vector<vector<int>> ans;
			//由于排序过 后面取index的时候会不准确
			sort(nums.begin(), nums.end());
			int n = nums.size();
			int second = nums.size()-1;
			
			for (int first = 0; first < nums.size(); first++) {
				while (first < second && nums[first] + nums[second]>target) {
					--second;
				}
				if (first == second) {
					break;
				}
				if (nums[first] + nums[second] == target) {
					res = vector<int>{nums[first], nums[second]};
					ans.push_back(res);
				}
			}
			return res;
		}

		//hash表格的方法
		vector<int> twoSum2(vector<int>& nums, int target) {
			unordered_map<int, int> hashtable;
			for (int i = 0; i < nums.size(); ++i) {
				auto it = hashtable.find(target - nums[i]);
				if (it != hashtable.end()) {
					return { it->second, i };
				}
				hashtable[nums[i]] = i;
			}
			return {};
		}

		//作者：LeetCode - Solution
		//	链接：https ://leetcode-cn.com/problems/two-sum/solution/liang-shu-zhi-he-by-leetcode-solution/
		//来源：力扣（LeetCode）
		//	著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
	};
}

void validation1() {
	// 2数和==target的所有不重复组合 拓展到p15 三数和==0
	vector<int> input_vec = { 2, 7, 11, 15, -4, 5, 4, -2 };
	vector<int> input_vec2 = { 3, 2, 4 };
	vector<int> output_vec;
	using namespace p1;
	Solution sol;
	output_vec = sol.twoSum2(input_vec, 7);
	cout << "input:" << endl;

}