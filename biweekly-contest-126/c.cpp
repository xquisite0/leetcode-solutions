// 3081. Replace Question Marks in String to Minimize Its Value
class Solution {
public:
  string minimizeStringValue(string s) {
    int hm[26];
    int empty = 0;
    memset(hm, 0, sizeof hm);
    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        pq;
    for (char c : s) {
      if (c == '?') {
        empty++;
        continue;
      }
      hm[c - 'a']++;
    }
    for (int i = 0; i < 26; i++) {
      pq.push({hm[i], i});
    }
    string t = "";
    while (empty) {
      int co, letter;
      auto p = pq.top();
      pq.pop();
      co = p.first, letter = p.second;
      t.push_back(letter + 'a');
      pq.push({co + 1, letter});
      empty--;
    }
    sort(t.begin(), t.end());
    int it = 0;

    for (int i = 0; i < s.size(); i++) {
      if (s[i] == '?') {
        s[i] = t[it];
        it++;
      }
    }
    return s;
  }
};