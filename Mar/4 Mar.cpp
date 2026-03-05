class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        int ans = 0;
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                int cnt = 0;
                if(mat[i][j] == 1)
                {
                    for(int k = 0; k < m; k++)
                    {
                        if(mat[k][j] == 1)
                            cnt++;
                    }
                    for(int l = 0; l < n; l++)
                    {
                        if(mat[i][l] == 1)
                            cnt++;
                    }
                }
                if(cnt == 2)
                    ans++;
            }
        }
        return ans;
    }
};