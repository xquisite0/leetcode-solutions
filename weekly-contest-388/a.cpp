// 3074. Apple Redistribution into Boxes
class Solution {
public:
  int minimumBoxes(vector<int> &apple, vector<int> &capacity) {
    int a = 0;
    for (int i : apple) {
      a += i;
    }
    sort(capacity.rbegin(), capacity.rend());
    int b = 0;
    for (int i = 0; i < capacity.size(); i++) {
      b += capacity[i];
      if (b >= a) {
        return i + 1;
      }
    }
    return 0;
  }
};