// 3080. Mark Elements on Array by Performing Queries
class Solution {
public:
  vector<long long> unmarkedSumArray(vector<int> &nums,
                                     vector<vector<int>> &queries) {
    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        pq;
    long long total = 0;
    for (int i = 0; i < nums.size(); i++) {
      pq.push({nums[i], i});
      total += nums[i];
    }
    vector<bool> marked(nums.size());
    vector<long long> ans;
    for (auto &q : queries) {
      if (!marked[q[0]]) {
        total -= nums[q[0]];
      }
      marked[q[0]] = true;
      while (!pq.empty() && q[1] > 0) {
        int curval, curi;
        auto p = pq.top();
        curval = p.first, curi = p.second;
        while (!pq.empty() && marked[curi]) {
          pq.pop();
          auto p = pq.top();
          curval = p.first, curi = p.second;
        }
        if (pq.empty()) {
          break;
        }
        total -= (long long)curval;
        marked[curi] = true;
        pq.pop();
        q[1]--;
      }
      ans.emplace_back(total);
    }
    return ans;
  }
};