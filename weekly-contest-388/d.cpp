// 3077. Maximum Strength of K Disjoint Subarrays
class Solution {
public:
  /*
  dp
  state - dp[i][j][flag]: the maximum strength of the subarray from nums[i...]
  where we are forming j subarrays and flag ==> whether we take the current
  value or not transition - dp[i][j][0] = max ( dp[i+1][j][0] or dp[i+1][j][1] )
  dp[i][j][1] = max ( dp[i+1][j-1][0] or dp[i+1][j][1] )

  base cases -
  j == 0 & i < n: return 0
  i == n && j != 0: return INT_MIN

  */
  vector<int> A;
  int k;
  vector<vector<vector<long long>>> memo;
  long long dp(int i, int j, int flag) {
    if (j == 0 && i <= A.size())
      return 0;
    if (i == A.size())
      return -1e15;
    if (memo[i][j][flag] != -1)
      return memo[i][j][flag];

    long long ans;
    if (flag == 0) {
      // 2 choices: don't select the next element, select the next element to
      // start a new subarray
      ans = max(dp(i + 1, j, 0), dp(i + 1, j, 1));
    } else {
      // int ele_strength = i % 2 == 0 ? 1 : -1;
      long long ele_strength = (long long)A[i] * (long long)j;
      ele_strength = (j % 2 == 1) ? ele_strength : -ele_strength;

      // 3 choices: don't select the next element, include the next element in
      // the current subarray, include the next element in the next subarray
      ans =
          max(dp(i + 1, j - 1, 0), max(dp(i + 1, j, 1), dp(i + 1, j - 1, 1))) +
          ele_strength;
    }
    // cout << i << " " << j << " " << flag << ": " << ans << endl;
    return memo[i][j][flag] = ans;
  }
  long long maximumStrength(vector<int> &nums, int k1) {
    A = move(nums);
    k = k1;
    memo.resize(A.size(),
                vector<vector<long long>>(k + 1, vector<long long>(2, -1)));
    return max(dp(0, k, 0), dp(0, k, 1));
  }
};