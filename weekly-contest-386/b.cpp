// 3047. Find the Largest Area of Square Inside Two Rectangles

class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        long long ans = 0;
        int n = bottomLeft.size();
        for (int i = 0; i < n; i++) {
            int botx = bottomLeft[i][0], boty = bottomLeft[i][1];
            int topx = topRight[i][0], topy = topRight[i][1];
            for (int j = i+1; j < n; j++) {
                int botx1 = bottomLeft[j][0], boty1 = bottomLeft[j][1];
                int topx1 = topRight[j][0], topy1 = topRight[j][1];
                
                
                long long x = max(0, min(topx, topx1) - max(botx, botx1));
                long long y = max(0, min(topy, topy1) - max(boty, boty1));
                ans = max(ans, min(x, y) * min(x, y));
                // if (ans == 25) {
                //     cout << i << " " << j << endl;
                //     cout << x << " " << y << endl;
                // }
            }
        }
        return ans;
    }
};