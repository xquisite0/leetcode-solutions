// 3092. Most Frequent IDs

class Solution {
public:
    vector<long long> mostFrequentIDs(vector<int>& nums, vector<int>& freq) {
        unordered_map<int, long long> hm;
        
        // count, id
        set<pair<long long, int>> s;
        vector<long long> ans;
        for (int i = 0; i < nums.size(); i++) {
            s.erase({hm[nums[i]], nums[i]});
            hm[nums[i]] += freq[i];
            s.insert({hm[nums[i]], nums[i]});
            ans.push_back(max((long long) 0, s.rbegin()->first));
        }
        return ans;
        // accoutn for negative ids
    }
};
