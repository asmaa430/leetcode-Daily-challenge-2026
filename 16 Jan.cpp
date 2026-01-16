class Solution {
public:
    const int mod = 1e9+7;
    
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        hFences.push_back(1);
        hFences.push_back(m);
        vFences.push_back(1);
        vFences.push_back(n);

        sort(hFences.begin(), hFences.end());
        sort(vFences.begin(), vFences.end());
        
        unordered_set<int> st;
        int hLen = hFences.size();
        int vLen = vFences.size();
        int maxi = 0;

        for(int i=0; i+1<hLen; ++i)
            for(int j=i+1; j<hLen; ++j)
                st.insert(hFences[j] - hFences[i]);

        for(int i=0; i+1<vLen; ++i)
            for(int j=i+1; j<vLen; ++j){
                int diff = vFences[j] - vFences[i];
                if(st.count(diff))
                    maxi = max(maxi, diff);
            }
        
        return maxi ? 1L*maxi*maxi % mod : -1;
    }

};