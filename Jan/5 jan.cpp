class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long sum=0;
        int n=matrix.size();
        int count=0;
        int mini=INT_MAX;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                sum+=abs(matrix[i][j]);
                if(matrix[i][j]<0)count++;
                mini=min(mini,abs(matrix[i][j]));

            }
        }
        if(count%2==0)return sum;
        else
        return sum-2*mini;
    }
};