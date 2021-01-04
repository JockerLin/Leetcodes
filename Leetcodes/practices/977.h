/*
 * author:	Lin Cunqin
 * version:	1.0
 * date:	2020.10.16
 * copyright:	Copyright 2020, Blazar
 * description: ����һ�����ǵݼ�˳��������������� A��
				����ÿ�����ֵ�ƽ����ɵ������飬Ҫ��Ҳ���ǵݼ�˳������
*/

#include "commoninclude.h"

namespace p977{
	class Solution {
	public:
		vector<int> sortedSquares(vector<int>& A) {
			vector<int> squares;
			if (A.size() >= 1 && A.size() <= 10000)
			{
				for (int i = 0; i < A.size(); i++) {
					squares.push_back(A[i] * A[i]);
				}

				//sort
				int mid_value;
				for (int i = 0; i < squares.size(); i++)
				{
					for (int j = i; j < squares.size(); j++) {
						if (squares[i] > squares[j]) {
							swap(squares[i], squares[j]);
							/*mid_value = squares[i];
							squares[i] = squares[j];
							squares[j] = mid_value;*/
						}
					}
				}
			}
			return squares;
		}

		vector<int> sortedSquares2(vector<int>& A) {
			vector<int> ans;
			//for �Ķ���д��
			for (int num : A) {
				ans.push_back(num * num);
			}
			sort(ans.begin(), ans.end());
			return ans;
		}

		//ʹ��˫ָ�� �м䵽���� ���õ������������Ǵ�С�����˳��
		vector<int> sortedSquares3(vector<int>& A) {
			vector<int> ans;

			//ȡ����ֵ����ֵ�Ľ���
			int neg_index = 0;
			for (int i = 0; i < A.size(); i++) {
				if (A[i] < 0) {
					neg_index = i;
				}
				else
					break;
			}

			int i = neg_index, j = neg_index + 1;
			vector<int> min_vector;
			while (i >= 0 || j < A.size()) {
				if (-1 == i)
				{
					min_vector.push_back(A[j] * A[j]);
					j++;
				}
				else if (A.size() == j) {
					min_vector.push_back(A[i] * A[i]);
					i--;
				}
				else if (A[i] * A[i] > A[j] * A[j]) {
					min_vector.push_back(A[j] * A[j]);
					j++;
				}
				else if (A[i] * A[i] < A[j] * A[j]) {
					min_vector.push_back(A[i] * A[i]);
					i--;
				}

				else {
					cout << "anything else???" << endl;
				}
				cout << "nibu good" << endl;
			}
			return min_vector;
		}

		// ˫ָ�뷨2 ���ߵ��м�
		vector<int> sortedSquares4(vector<int>& A) {
			int n = A.size();
			vector<int> ans(n);
			for (int i = 0, j = n - 1, pos = n - 1; i <= j;) {
				if (A[i] * A[i] > A[j] * A[j]) {
					ans[pos] = A[i] * A[i];
					++i;
				}
				else {
					ans[pos] = A[j] * A[j];
					--j;
				}
				--pos;
			}
			return ans;

		}

	};
}


void validation977() {
	vector<int> input_vec = { -4, -1, 0, 3, 10 };
	vector<int> output_vec;
	using namespace p977;
	Solution sol;
	output_vec=sol.sortedSquares4(input_vec);
	cout << "input:"  << endl;

}