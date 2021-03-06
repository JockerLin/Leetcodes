#pragma once
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
#include <unordered_set>

using namespace std;


namespace p3 {
	class Solution {
	public:
		int lengthOfLongestSubstring(string s) {
			// 哈希集合，记录每个字符是否出现过
			unordered_set<char> occ;
			int n = s.size();
			// 右指针，初始值为 -1，相当于我们在字符串的左边界的左侧，还没有开始移动
			int rk = -1, ans = 0;
			// 枚举左指针的位置，初始值隐性地表示为 -1
			for (int i = 0; i < n; ++i) {
				if (i != 0) {
					// 左指针向右移动一格，移除一个字符
					occ.erase(s[i - 1]);
				}
				while (rk + 1 < n && !occ.count(s[rk + 1])) {
					// 不断地移动右指针
					occ.insert(s[rk + 1]);
					++rk;
				}
				// 第 i 到 rk 个字符是一个极长的无重复字符子串
				ans = max(ans, rk - i + 1);
			}
			return ans;
		}
	};

	//作者：LeetCode - Solution
	//	链接：https ://leetcode-cn.com/problems/longest-substring-without-repeating-characters/solution/wu-zhong-fu-zi-fu-de-zui-chang-zi-chuan-by-leetc-2/
	//来源：力扣（LeetCode）
	//	著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
}

void validation3() {
	using namespace p3;
	Solution sol;
	string test_str = "pwwkew";
	sol.lengthOfLongestSubstring(test_str);
}