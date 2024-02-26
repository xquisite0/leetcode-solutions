// 3046. Split the Array

class Solution {
public:
    bool isPossibleToSplit(vector<int>& nums) {
        unordered_map<int, int> m;
        for (int i : nums) {
            m[i]++;
        }
        for (auto p : m) {
            if (p.second > 2) return false;
        }
        return true;
    }
};