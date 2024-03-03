// 3072. Distribute Elements Into Two Arrays II

class Solution {
public:
  int n = 100000;
  int ft1[100005], ft2[100005];
  int query(int p, int i) {
    int sum = 0;
    for (; p; p -= (p & -p)) {
      if (i == 1)
        sum += ft1[p];
      else
        sum += ft2[p];
    }
    return sum;
  }
  void update(int p, int v, int i) {
    for (; p <= n; p += (p & -p)) {
      if (i == 1)
        ft1[p] += v;
      else
        ft2[p] += v;
    }
  }
  vector<int> resultArray(vector<int> &nums) {
    int n = nums.size();
    set<int> nums2;
    unordered_map<int, int> hm;
    for (int i : nums) {
      nums2.insert(i);
    }
    // sort(nums2.begin(), nums2.end());
    int pos = 1;
    for (int i : nums2) {
      hm[i] = pos;
      pos++;
    }
    vector<int> a, b;
    a.push_back(nums[0]);
    update(hm[nums[0]], 1, 1);
    b.push_back(nums[1]);
    update(hm[nums[1]], 1, 2);
    for (int i = 2; i < n; i++) {
      int gc1 = a.size() - query(hm[nums[i]], 1);
      int gc2 = b.size() - query(hm[nums[i]], 2);
      if (gc1 > gc2) {
        a.push_back(nums[i]);
        update(hm[nums[i]], 1, 1);
      } else if (gc1 < gc2) {
        b.push_back(nums[i]);
        update(hm[nums[i]], 1, 2);
      } else {
        if (a.size() > b.size()) {
          b.push_back(nums[i]);
          update(hm[nums[i]], 1, 2);
        } else {
          a.push_back(nums[i]);
          update(hm[nums[i]], 1, 1);
        }
      }
    }
    a.insert(a.end(), b.begin(), b.end());
    return a;
  }
};