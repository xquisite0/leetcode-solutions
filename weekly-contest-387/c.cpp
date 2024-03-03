// 3071. Minimum Operations to Write the Letter Y on a Grid

class Solution {
public:
  int minimumOperationsToWriteY(vector<vector<int>> &grid) {
    int y[3];
    int noty[3];
    memset(y, 0, sizeof y);
    memset(noty, 0, sizeof y);

    int n = grid.size();
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        bool isy = false;
        if (i == j && i <= n / 2) {
          isy = true;
        }
        if (i == n - 1 - j && i <= n / 2) {
          isy = true;
        }
        if (j == n / 2 && i >= n / 2) {
          isy = true;
        }
        if (!isy) {
          noty[grid[i][j]]++;
        } else
          y[grid[i][j]]++;
      }
    }
    // for (int i = 0; i < 3; i++) cout << y[i] << " ";
    // cout << endl;
    // for (int i = 0; i < 3; i++) cout << noty[i] << " ";
    // cout << endl;
    // return 0;
    int ans = INT_MAX;
    ans = min(ans, y[1] + y[2] + noty[0] + noty[2]);
    ans = min(ans, y[1] + y[2] + noty[0] + noty[1]);
    ans = min(ans, y[0] + y[2] + noty[1] + noty[2]);
    ans = min(ans, y[0] + y[2] + noty[0] + noty[1]);
    ans = min(ans, y[1] + y[0] + noty[1] + noty[2]);
    ans = min(ans, y[1] + y[0] + noty[0] + noty[2]);
    return ans;
  }
};