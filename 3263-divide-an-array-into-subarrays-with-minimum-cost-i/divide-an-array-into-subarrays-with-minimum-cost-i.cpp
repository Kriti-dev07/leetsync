class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int f=INT_MAX, s=INT_MAX;
        for( int i=1;i<nums.size();i++){
            if(nums[i]<f){
                s=f;
                f=nums[i];
            }
            else if(nums[i] < s) {
                s=nums[i];
                
            }
        }
      return nums[0] + f + s;
    }
};
