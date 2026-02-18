class Solution {
public:
    bool hasAlternatingBits(int n) {
        int res1 = n % 2;
        n /= 2;
        while (n > 0) {
            int res2 = n % 2;
            if (res1 == res2)
                return false;
            res1 = res2;
            n /= 2;
        }
        return true;
    }
};