/*
 * author:	Lin Cunqin
 * version:	1.0
 * date:	2020.10.16
 * copyright:	Copyright 2020, Blazar
 * description: Ҫ���ҵ����С����ظ����Һ�Ϊ 00 ����Ԫ��
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
			// ö�� a
			for (int first = 0; first < n; ++first) {
				// ��Ҫ����һ��ö�ٵ�������ͬ
				if (first > 0 && nums[first] == nums[first - 1]) {
					continue;
				}
				// c ��Ӧ��ָ���ʼָ����������Ҷ�
				int third = n - 1;
				int target = -nums[first];
				// ö�� b
				for (int second = first + 1; second < n; ++second) {
					// ��Ҫ����һ��ö�ٵ�������ͬ
					if (second > first + 1 && nums[second] == nums[second - 1]) {
						continue;
					}
					// ��Ҫ��֤ b ��ָ���� c ��ָ������
					while (second < third && nums[second] + nums[third] > target) {
						--third;
					}
					// ���ָ���غϣ����� b ����������
					// �Ͳ��������� a+b+c=0 ���� b<c �� c �ˣ������˳�ѭ��
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

	//���ߣ�LeetCode - Solution
	//	���ӣ�https ://leetcode-cn.com/problems/3sum/solution/san-shu-zhi-he-by-leetcode-solution/
	//��Դ�����ۣ�LeetCode��
	//	����Ȩ���������С���ҵת������ϵ���߻����Ȩ������ҵת����ע��������
}

// �����ǲ�����˫ָ���˼·��ͬʱҲҪ�����ظ�


void validation15() {
	// 3����==0�����в��ظ����
	vector<int> input_vec = { -1, 0, 1, 2, -1, -4 };
	vector<int> input_vec2 = { 0, 0, 0, 0, 0, 0 };
	vector<vector<int>> output_vec;
	using namespace p15;
	Solution sol;
	output_vec = sol.threeSum(input_vec);
	cout << "input:" << endl;

}