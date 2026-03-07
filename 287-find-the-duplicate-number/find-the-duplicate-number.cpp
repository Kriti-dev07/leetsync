class Solution {
public:
/* solution using unordered map 
unordered_map<int> seen;
for(auto num: nums){
    if(seen.count(num)){
        return num ;

    }
    seen.insert(num);
}
return -1;
}};
*/
    int findDuplicate(vector<int>& nums) {
        int slow=nums[0];
        int fast=nums[0];
        do{
            slow=nums[slow];
            fast=nums[nums[fast]];

        }
        while(slow!=fast);
            slow=nums[0];
            while(slow!=fast){
                slow=nums[slow];
                fast=nums[fast];

            }
            return slow;
        }
    
};