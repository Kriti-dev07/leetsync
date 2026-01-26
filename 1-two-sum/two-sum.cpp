class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int,int> hello;
   for (int i = 0; i < nums.size(); i++)
{
        int compliment=target-nums[i];
        if(hello.count(compliment)){
            return {hello[compliment],i};
        }

       else{ 
        hello[nums[i]]=i;}
    }
        return{};

    }
    };