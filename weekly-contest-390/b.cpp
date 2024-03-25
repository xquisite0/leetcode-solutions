// 3091. Apply Operations to Make Sum of Array Greater Than or Equal to k

class Solution {
public:
    int minOperations(int k) {
        if (k == 1) return 0;
        int ans = INT_MAX;
        for (int i = 1; i <= k; i++) {
            ans = min(ans, ((k+i-1) / i)-1 + i - 1);
        }
        return ans;
    }
};
