#pragma once
/*
 * author:	Lin Cunqin
 * version:	1.0
 * date:	2020.10.16
 * copyright:	Copyright 2020, Blazar
 * description: Ҫ���ҵ����С����ظ����Һ�Ϊ target �Ķ�Ԫ��
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
			// ��ϣ���ϣ���¼ÿ���ַ��Ƿ���ֹ�
			unordered_set<char> occ;
			int n = s.size();
			// ��ָ�룬��ʼֵΪ -1���൱���������ַ�������߽����࣬��û�п�ʼ�ƶ�
			int rk = -1, ans = 0;
			// ö����ָ���λ�ã���ʼֵ���Եر�ʾΪ -1
			for (int i = 0; i < n; ++i) {
				if (i != 0) {
					// ��ָ�������ƶ�һ���Ƴ�һ���ַ�
					occ.erase(s[i - 1]);
				}
				while (rk + 1 < n && !occ.count(s[rk + 1])) {
					// ���ϵ��ƶ���ָ��
					occ.insert(s[rk + 1]);
					++rk;
				}
				// �� i �� rk ���ַ���һ�����������ظ��ַ��Ӵ�
				ans = max(ans, rk - i + 1);
			}
			return ans;
		}
	};

	//���ߣ�LeetCode - Solution
	//	���ӣ�https ://leetcode-cn.com/problems/longest-substring-without-repeating-characters/solution/wu-zhong-fu-zi-fu-de-zui-chang-zi-chuan-by-leetc-2/
	//��Դ�����ۣ�LeetCode��
	//	����Ȩ���������С���ҵת������ϵ���߻����Ȩ������ҵת����ע��������
}

void validation3() {
	using namespace p3;
	Solution sol;
	string test_str = "pwwkew";
	sol.lengthOfLongestSubstring(test_str);
}