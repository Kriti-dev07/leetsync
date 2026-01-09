class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        long long sum = 0;  //sum of current window
        int l = 0;     //left pointer of window 
        int ans = 0;     //maximum window size answer 

        for (int r = 0; r < nums.size(); r++) {   //we keep expanding window to the right 
            sum += nums[r];

            while ((long long)nums[r] * (r - l + 1) - sum > k) {   
                sum -= nums[l];
                l++;
            }

            ans = max(ans, r - l + 1);   // needed to find best answer ..give example[1,2,4,8] answer will be 2 in this case but better answer 3 is vailable 
        }
        return ans;
    }
};
