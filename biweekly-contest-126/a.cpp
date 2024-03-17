// 3079. Find the Sum of Encrypted Integers
class Solution {
public:
  int sumOfEncryptedInt(vector<int> &nums) {
    int ans = 0;
    for (int i : nums) {
      int l = 0;
      int si = 0;
      while (i) {
        l = max(l, i % 10);
        i /= 10;
        si++;
      }
      int pow = 1;
      for (int j = 0; j < si; j++) {
        ans += pow * l;
        pow *= 10;
      }
    }
    return ans;
  }
};