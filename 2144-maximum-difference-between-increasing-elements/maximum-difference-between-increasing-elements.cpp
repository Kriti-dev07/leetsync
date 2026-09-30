class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n=nums.size();
        int mini=nums[0];
        int max_diff=0;
        for(int i=0;i<n;i++){
            mini=min(mini,nums[i]);
            max_diff=max(max_diff,nums[i]-mini);
        }
if (max_diff>0){
    return max_diff;
}
else{
    return -1;
}
    }
};