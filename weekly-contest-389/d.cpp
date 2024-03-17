// 3086. Minimum Moves to Pick K Ones

class Solution {
public:
  long long minimumMoves(vector<int> &A, int k, int maxChanges) {
    int n = A.size();
    // closest x 1s
    int x1 = k - maxChanges - 1;

    vector<long long> B;
    for (int i = 0; i < n; i++)
      if (A[i])
        B.push_back(i);
    vector<long long> C;

    if (B.empty()) {
      return 2 * k;
    }

    // sliding window of distances

    long long x = x1;
    if (x > 0) {
      long long l = 0, r = x;
      long long sumd = 0;
      for (int i = 1; i <= x; i++)
        sumd += B[i] - B[0];
      C.push_back(sumd);

      long long lco = 1, rco = x;
      for (int i = 1; i < B.size(); i++) {
        sumd += lco * (B[i] - B[i - 1]);
        sumd -= rco * (B[i] - B[i - 1]);

        if (r < i) {
          sumd -= B[i] - B[l];
          l++, r++;
          lco--, rco++;
        }
        // cout << l << " " << r << " " << sumd << endl;

        // should i shift my window up?
        while (r < B.size() - 1 && B[i] - B[l] > B[r + 1] - B[i]) {
          sumd -= B[i] - B[l];
          sumd += B[r + 1] - B[i];
          l++, r++;
          lco--, rco++;
        }
        C.push_back(sumd);
        lco++, rco--;
        // cout << i << " " << lco << " " << rco << endl;
      }
    }
    //         cout << "B: ";
    //         for (int i : B) cout << i << " ";
    //         cout << endl;

    //         cout << "C: ";
    //         for (int i : C) cout << i << " ";
    //         cout << endl;

    long long ans = LLONG_MAX;
    for (int i = 0; i < B.size(); i++) {
      // cout << i << " " << ans << endl;
      int Ai = B[i];
      int to_pick = k - 1;
      long long moves = 0;

      if (to_pick == 0) {
        if (moves < ans)
          ans = moves;
        continue;
      }

      if (Ai > 0 && A[Ai - 1]) {
        to_pick--;
        moves++;
      }

      if (to_pick == 0) {
        if (moves < ans)
          ans = moves;
        continue;
      }

      if (Ai < A.size() - 1 && A[Ai + 1]) {
        to_pick--;
        moves++;
      }

      if (to_pick == 0) {
        if (moves < ans)
          ans = moves;
        continue;
      }

      moves += 2 * min(to_pick, maxChanges);
      to_pick -= min(to_pick, maxChanges);

      if (to_pick == 0) {
        if (moves < ans)
          ans = moves;
        continue;
      }

      if (to_pick == x1) {

        moves += C[i];
        // cout << i << " " << to_pick << " " << maxChanges << " " << moves <<
        // endl;
        to_pick = 0;
      } else if (to_pick == x1 - 1) {
        moves += C[i] - 1;
        // cout << i << " " << to_pick << " " << maxChanges << " " << moves <<
        // endl;
        to_pick = 0;
      } else if (to_pick == x1 - 2) {
        moves += C[i] - 2;
        // cout << i << " " << to_pick << " " << maxChanges << " " << moves <<
        // endl;
        to_pick = 0;
      }

      if (to_pick == 0) {
        if (moves < ans)
          ans = moves;
        continue;
      }
    }
    return ans;
  }
};

/*
Iterate through each index i and manually calculate the minimum moves if Dylan
started at index i

In order of taking 1s,
1) take the 1 at DylanIndex
2) take the 1s adjacent DylanIndex, if present
3) Exhaust all maxChanges 1s, put at adjacent and swap to DylanIndex
4) Reach to the various 1s closest to DylanIndex **** (how to calculate this
distance efficiently?)

indexes : i-1 i i+1
Case 1:
0 1 0
k--
if maxChanges >= k -> moves = 2 * k
if maxChanges < k -> moves = 2 * maxChanges + SUM(distance to k - maxChanges
closest ones)

Case 2:
0 1 1 / 1 1 0

if maxChanges >= k -> moves = 2 * k
if maxChanges < k -> moves = 2 * maxChanges + SUM(distance to k - maxChanges
closest ones)

Case 3:
1 1 1


All 0: handle separately.
*/