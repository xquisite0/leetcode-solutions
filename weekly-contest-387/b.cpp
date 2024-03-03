// 3070. Count Submatrices with Top-Left Element and Sum Less Than k

class Solution {
public:
  int countSubmatrices(vector<vector<int>> &grid, int k) {
    int n = grid.size(), m = grid[0].size();
    int ans = 0;
    vector<int> a(m);
    for (int i = 0; i < n; i++) {
      int cur = 0;
      bool works = true;
      for (int j = 0; j < m; j++) {
        a[j] += grid[i][j];
        cur += a[j];
        if (cur <= k) {
          ans++;
        }
      }

      // if (!works) {
      //     break;
      // }
    }
    return ans;
  }
};