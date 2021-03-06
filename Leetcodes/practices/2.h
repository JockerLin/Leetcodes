﻿#pragma once
/*
 * author:	Lin Cunqin
 * version:	1.0
 * date:	2020.10.19
 * copyright:	Copyright 2020, Blazar
 * description: 
给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。

如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。

您可以假设除了数字 0 之外，这两个数都不会以 0 开头

示例：

输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
输出：7 -> 0 -> 8
原因：342 + 465 = 807

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/add-two-numbers
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

/**
	 *
	 *思路
	 * 标签：链表
	 *      将两个链表看成是相同长度的进行遍历，如果一个链表较短则在前面补 0，比如 987 + 23 = 987 + 023 = 1010
	 *      每一位计算的同时需要考虑上一位的进位问题，而当前位计算结束后同样需要更新进位值
	 *      如果两个链表全部遍历完毕后，进位值为 11，则在新链表最前方添加节点 11
	 * 小技巧：对于链表问题，返回结果为头结点时，通常需要先初始化一个预先指针 pre，
	 *        该指针的下一个节点指向真正的头结点head。使用预先指针的目的在于链表初始化时无可用节点值，
	 *        而且链表构造过程需要指针移动，进而会导致头指针丢失，无法返回结果。
	 *
	 * 作者：guanpengchn
	 * 链接：https://leetcode-cn.com/problems/add-two-numbers/solution/hua-jie-suan-fa-2-liang-shu-xiang-jia-by-guanpengc/
	 * 来源：力扣（LeetCode）
	 * 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
	 *
	 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

namespace p2 {
	struct ListNode {
		int val;
		ListNode *next;
		ListNode() : val(0), next(nullptr) {}
		ListNode(int x) : val(x), next(nullptr) {}
		ListNode(int x, ListNode *next) : val(x), next(next) {}
		
	};

	class Solution {
	public:
		ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
			ListNode *head = nullptr, *tail = nullptr;
			int carry = 0;
			while (l1 || l2) {
				int n1 = l1 ? l1->val : 0;
				int n2 = l2 ? l2->val : 0;
				int sum = n1 + n2 + carry;
				if (!head) {
					head = tail = new ListNode(sum % 10);
				}
				else {
					tail->next = new ListNode(sum % 10);
					tail = tail->next;
				}
				carry = sum / 10;
				if (l1) {
					l1 = l1->next;
				}
				if (l2) {
					l2 = l2->next;
				}
			}
			if (carry > 0) {
				tail->next = new ListNode(carry);
			}
			return head;
		}
	};


}

void validation2() {

	using namespace p2;
	Solution sol;
	ListNode* l1 = new ListNode(2);
	ListNode* l2 = new ListNode(4);
	ListNode* l3 = new ListNode(3);
	l1->next = l2;
	l2->next = l3;

	ListNode* l4 = new ListNode(5);
	ListNode* l5 = new ListNode(6);
	ListNode* l6 = new ListNode(9);
	l4->next = l5;
	l5->next = l6;
	ListNode* listNode = sol.addTwoNumbers(l1, l4);
	// 342+965=1307
	while (listNode != NULL) {
		cout << listNode->val << endl;
		listNode = listNode->next;
	}
	cout << "finish" << endl;

}