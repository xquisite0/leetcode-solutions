// 3090. Maximum Length Substring With Two Occurrences

class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            // string cur = "";
            unordered_map<char, int> hm;
            int length = 0;
            for (int j = i; j < n; j++) {
                // cur += s[i];
                hm[s[j]]++;
                
                if (hm[s[j]] == 3) break;
                length++;
            }
            if (i == 4) cout << length << endl;
            ans= max(ans, length);
        }
        return ans;
    }
};
