class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        string ans = string (n,'0');
        if(find(nums.begin(),nums.end(),ans)==nums.end())
            return ans;
        for(int i = 0; i < nums.size(); i++) { 
            ans[i] = '1';  
            if(find(nums.begin(), nums.end(), ans) == nums.end()) 
                return ans;  
            ans[i] = '0'; 
        }
        return ans;  
    }
};