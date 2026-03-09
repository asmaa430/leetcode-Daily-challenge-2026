class Solution {
public:
    int numberOfStableArrays(int zero, int one, int limit) {
        int dp[201][201][2] , M = 1e9 + 7;
        memset(dp , 0 , sizeof(dp));
        dp[0][0][0] = dp[0][0][1] = 1;
        for(int leftZero=0;leftZero<=zero;leftZero++){
            for(int leftOne=0;leftOne<=one;leftOne++){
                if(leftZero == 0 && leftOne == 0) continue;
                int result = 0;
                for(int len=1;len<=min(leftZero,limit);len++){
                    result = (result + dp[leftZero - len][leftOne][0]) % M;
                }
                dp[leftZero][leftOne][1] = result;
                result = 0;
                for(int len=1;len<=min(leftOne,limit);len++){
                    result = (result + dp[leftZero][leftOne-len][1]) % M;
                }
                dp[leftZero][leftOne][0] = result;
            }
        }
        return (dp[zero][one][0] + dp[zero][one][1])%M;
    }
};