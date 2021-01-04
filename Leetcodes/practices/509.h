#pragma once

#include "commoninclude.h"

namespace p509 {
        // µ›πÈ
        class Solution {
        public:
            int fib(int n) {
                if (n == 0) return 0;
                else if (n == 1) return 1;
                return fib(n - 1) + fib(n - 2);
            }
        };
        //// º«“‰ªØ
        //class Solution {
        //public:
        //    int a[40];
        //    int fib(int n) {
        //        memset(a, -1, sizeof a);
        //        a[0] = 0, a[1] = 1;
        //        return ff(n);
        //    }

        //    int ff(int n) {
        //        if (a[n] != -1) return a[n];
        //        a[n] = ff(n - 1) + ff(n - 2);
        //        return a[n];
        //    }
        //};
        //// dp
        //class Solution {
        //public:
        //    int a[40];
        //    int fib(int n) {
        //        a[0] = 0, a[1] = 1;
        //        for (int i = 2; i <= n; i++) {
        //            a[i] = a[i - 1] + a[i - 2];
        //        }
        //        return a[n];
        //    }
        //};


}

void validation509() {
    using namespace p509;
    Solution sol;
    int res = sol.fib(4);
    cout << res << endl;
}
