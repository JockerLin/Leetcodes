#pragma once

/*
假设有一个很长的花坛，一部分地块种植了花，另一部分却没有。可是，花不能种植在相邻的地块上，它们会争夺水源，两者都会死去。

给你一个整数数组  flowerbed 表示花坛，由若干 0 和 1 组成，其中 0 表示没种植花，1 表示种植了花。另有一个数 n ，能否在不打破种植规则的情况下种入 n 朵花？能则返回 true ，不能则返回 false。

*/

#include "commoninclude.h"

namespace p605 {
    class Solution {
    public:
        bool canPlaceFlowers(vector<int>& flowerbed, int n) {
            // 每次跳两格
            for (int i = 0; i < flowerbed.size(); i += 2) {
                // 如果当前为空地
                if (flowerbed[i] == 0) {
                    // 如果是最后一格或者下一格为空
                    if (i == flowerbed.size() - 1 || flowerbed[i + 1] == 0) {
                        n--;
                    }
                    else {
                        i++;
                    }
                }
            }
            return n <= 0;
        }
    };
}

void validation605() {
    vector<int> flowerbed = { 1, 0, 0, 0, 1 };
    int n = 2;
    using namespace p605;
    Solution sol;
    bool res = sol.canPlaceFlowers(flowerbed, n);
    cout << res << endl;
}
