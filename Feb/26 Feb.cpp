class Solution {
public:
    long long binToDec(string s) {
        long long base = 1;
        long long dec = 0;

        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] == '1')
                dec += base;
            base *= 2;
        }
        return dec;
    }

    int numSteps(string s) {
        long long num = binToDec(s);
        int steps = 0;

        while (num != 1) {
            if (num & 1)  // odd
                num += 1;
            else
                num /= 2;

            steps++;
        }
        return steps;
    }
};