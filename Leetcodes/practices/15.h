/*
 * author:	Lin Cunqin
 * version:	1.0
 * date:	2020.10.16
 * copyright:	Copyright 2020, Blazar
 * description: 要求找到所有「不重复」且和为 00 的三元组
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

namespace p15 {
	class Solution {
	public:
		vector<vector<int>> threeSum(vector<int>& nums) {
			int n = nums.size();
			sort(nums.begin(), nums.end());
			vector<vector<int>> ans;
			// 枚举 a
			for (int first = 0; first < n; ++first) {
				// 需要和上一次枚举的数不相同
				if (first > 0 && nums[first] == nums[first - 1]) {
					continue;
				}
				// c 对应的指针初始指向数组的最右端
				int third = n - 1;
				int target = -nums[first];
				// 枚举 b
				for (int second = first + 1; second < n; ++second) {
					// 需要和上一次枚举的数不相同
					if (second > first + 1 && nums[second] == nums[second - 1]) {
						continue;
					}
					// 需要保证 b 的指针在 c 的指针的左侧
					while (second < third && nums[second] + nums[third] > target) {
						--third;
					}
					// 如果指针重合，随着 b 后续的增加
					// 就不会有满足 a+b+c=0 并且 b<c 的 c 了，可以退出循环
					if (second == third) {
						break;
					}
					if (nums[second] + nums[third] == target) {
						ans.push_back({ nums[first], nums[second], nums[third] });
					}
				}
			}
			return ans;
		}
	};

	//作者：LeetCode - Solution
	//	链接：https ://leetcode-cn.com/problems/3sum/solution/san-shu-zhi-he-by-leetcode-solution/
	//来源：力扣（LeetCode）
	//	著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
}

// 依旧是采用了双指针的思路，同时也要避免重复


void validation15() {
	// 3数和==0的所有不重复组合
	vector<int> input_vec = { -1, 0, 1, 2, -1, -4 };
	vector<int> input_vec2 = { 0, 0, 0, 0, 0, 0 };
	vector<vector<int>> output_vec;
	using namespace p15;
	Solution sol;
	output_vec = sol.threeSum(input_vec);
	cout << "input:" << endl;

}