// 3075. Maximize Happiness of Selected Children
class Solution {
public:
  long long maximumHappinessSum(vector<int> &A, int k) {
    priority_queue<int> pq;
    for (int i : A) {
      pq.push(i);
    }
    long long offset = 0;
    long long ans = 0;
    for (int i = 0; i < k; i++) {
      if (pq.top() <= offset)
        break;
      ans += pq.top();
      pq.pop();
      ans -= offset;
      offset++;
    }
    return ans;
  }
};