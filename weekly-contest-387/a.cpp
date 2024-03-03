// 3069. Distribute Elements Into Two Arrays I

class Solution {
public:
  vector<int> resultArray(vector<int> &nums) {
    vector<int> a, b, c;
    a.push_back(nums[0]);
    b.push_back(nums[1]);
    for (int i = 3; i <= nums.size(); i++) {
      if (a.back() > b.back()) {
        a.push_back(nums[i - 1]);
      } else {
        b.push_back(nums[i - 1]);
      }
    }
    a.insert(a.end(), b.begin(), b.end());
    return a;
  }
};