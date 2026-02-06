class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int idx=0;
        int i=0;
        while( i<= nums.size()-1){
            if(nums[i]!=0){
                nums[idx]=nums[i];
                idx++;

            }
            i++;

        }
        while(idx<=nums.size()-1){
            nums[idx]=0;
            idx++;

        }
    }
};
