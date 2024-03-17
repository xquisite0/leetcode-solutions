// 3085. Minimum Deletions to Make String K-Special
class Solution {
public:
  int minimumDeletions(string word, int k) {
    int hm[26];
    memset(hm, 0, sizeof hm);
    for (char c : word) {
      hm[c - 'a']++;
    }
    vector<int> A;
    for (int i = 0; i < 26; i++) {
      A.push_back(hm[i]);
    }
    sort(A.begin(), A.end());

    int ans = INT_MAX;
    int pref = 0;
    for (int i = 0; i < 26; i++) {
      int cur = pref;
      for (int j = i + 1; j < 26; j++) {
        if (A[j] > A[i] + k) {
          cur += A[j] - A[i] - k;
        }
      }
      ans = min(ans, cur);
      pref += A[i];
    }
    return ans;
  }
};