// 3082. Find the Sum of the Power of All Subsequences
class Solution {
public:
  /*
  dp:
  state (i, k, si): number of subsequences of size si, starting from i that sum
  up to value k
  */
  vector<int> A;
  vector<long long> pow = vector<long long>(105);
  vector<vector<vector<long long>>> memo;
  int MOD = 1e9 + 7;

  long long dp(int i, int j, int si) {
    if (j == 0 && si == 0) {
      return 1;
    } else if (i == A.size() || j <= 0 || si <= 0) {
      return 0;
    }
    if (memo[i][j][si] != -1)
      return memo[i][j][si];
    return memo[i][j][si] =
               (dp(i + 1, j - A[i], si - 1) + dp(i + 1, j, si)) % MOD;
  }
  int sumOfPower(vector<int> &nums, int k) {
    A = move(nums);
    pow[0] = 1;
    memo.resize(A.size(), vector<vector<long long>>(
                              k + 1, vector<long long>(A.size() + 1, -1)));
    for (int i = 1; i <= A.size(); i++) {
      pow[i] = pow[i - 1] * 2;
      pow[i] %= MOD;
    }

    long long ans = 0;
    for (int i = 1; i <= A.size(); i++) {
      long long number = dp(0, k, i);
      // cout << i << " " << number << endl;
      ans += pow[A.size() - i] * number;
      ans %= MOD;
    }
    return ans;
  }
};