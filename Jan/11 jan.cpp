class Solution {
public:
    int maximalRectangle(vector<vector<char>>& a) {
        int n = a.size();
        int m = a[0].size();
        vector<int> h(m, 0);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i][j] == '1')
                    h[j] += 1;
                else
                    h[j] = 0;
            }
            for (int j = m - 1; j >= 0; j--) {
                if (a[i][j] == '0')
                    continue;
                int minHeight = INT_MAX;
                for (int k = j; k >= 0; k--) {
                    minHeight = min(minHeight, h[k]);
                    ans = max(ans, minHeight * (j - k + 1)); 
                }
            }
        }
        return ans;
    }
};