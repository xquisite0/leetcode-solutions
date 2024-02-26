// 3049. Earliest Second to Mark Indices II (upsolved)

class Solution {
public:
    int earliestSecondToMarkIndices(vector<int>& nums, vector<int>& changeIndices) {
        int ans = 0;
        int n = nums.size(), m = changeIndices.size();
        vector<int> hm(n+1);
        unordered_set<int> firstindices;
        for (int t = 1; t <= m; t++) {
            if (hm[changeIndices[t-1]] == 0 && nums[changeIndices[t-1]-1] > 0) {
                hm[changeIndices[t-1]] = t;
                firstindices.insert(t);
            }
        }
        
        long long numssum = 0;
        for (int i : nums) {
            numssum += (long long) i;
        }
        // for (int i = 1; i <= n; i++) {
        //     cout << i << ": " << hm[i] << endl;
        // }
        // cout << endl;
        multiset<int> s;
        int l = 0;
        int r = m+1;
        while (r - l > 1) {
            
            int t = l + (r-l) / 2;
            cout << t << "\n";
            s.clear();
            // cout << "initial set size: " << s.size() << "\n";
            // the amount of times we mark 
            long long setsum = 0;
            int markOrDecrement = 0;
            for (int curt = t; curt >= 1; curt--) {
                if (firstindices.find(curt) != firstindices.end()) {
                    // cout << "ran";
                    s.insert(nums[changeIndices[curt-1]-1]);
                    setsum += nums[changeIndices[curt-1]-1];
                    // we can reduce this current element to 0
                    if (markOrDecrement > 0) {
                        // we will mark it sometime in the future. 
                        markOrDecrement--;
                    } else {
                        markOrDecrement++;
                        setsum -= *(s.begin());
                        // cout << "erased. ";
                        s.erase(s.begin());
                    }
                } else {
                    markOrDecrement++;
                }
            }
            // cout << t << " : " << numssum << " " << setsum << " " << n << " " << s.size() << endl;
            // markOrDecrement now represents the amount of time spaces we have to decrement all elements not in s + mark them
            if (numssum - setsum + n - s.size() <= markOrDecrement) {
                // cout << r << "\n";
                r = t;
            } else {
                l = t;
            }
        }
        if (r <= m) return r;
        else return -1;
        
        // return -1;
    }
};

/*
let's iterate from the back of the array to the front
whenever we encounter an index in changeIndices which is in first indices,
    2 cases will occur
    first case: we have time to mark i in nums in the future (markOrDecrement > 0)
    second case: we don't. (markOrDecrement == 0). In that case we give up bringing to 0 the i in nums where nums[i] is the minimum 
    
*/