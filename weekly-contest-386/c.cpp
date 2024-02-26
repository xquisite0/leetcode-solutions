// 3048. Earliest Second to Mark Indices I

class Solution {
public:
    int earliestSecondToMarkIndices(vector<int>& nums, vector<int>& changeIndices) {
        int n = nums.size(), m = changeIndices.size();
        
        vector<vector<int>> marktimes(n+1);
        
        for (int t = 1; t <= m; t++) {
            marktimes[changeIndices[t-1]].push_back(t);
        }
        // for (int i = 1; i <= n; i++) {
        //     cout << i << ": ";
        //     for (int j : marktimes[i]) cout << j << " ";
        //     cout << endl;
        // }
        vector<pair<int, int>> indexmarkedat(n);
        for (int t = 1; t <= m; t++) {
            indexmarkedat.clear();
            
            bool works = true;
            for (int i = 1; i <= n; i++) {
                int id = (upper_bound(marktimes[i].begin(), marktimes[i].end(), t) - marktimes[i].begin());
                id--;
                // cout << i << ": " << id << endl;
                if (id < 0) {
                    works = false;
                    break;
                }
                indexmarkedat.push_back({marktimes[i][id], i});
            }
            if (!works) continue;
            sort(indexmarkedat.begin(), indexmarkedat.end());
            
            int decremented = 0;
            for (int i = 0; i < n; i++) {
                int curt = indexmarkedat[i].first, curi = indexmarkedat[i].second;
                // cout << curt << " " << curi << "!\n";
                decremented += nums[curi-1];
                if (decremented >= curt) {
                    works = false;
                    break;
                }
                decremented++;
            }
            if (works) return t;
            
        }
            
        return -1;
    }
};