/*Most optimal:
Time complexity:O(n) average case but in worst case hash collisons it can degrade O(n^2) 
Space complexity:O(n)
*/
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



/*Brute Force
Time complexity: O(n^2)
Space complexity:O(1)*/
class solution{
public:
vector<int> twoSum(vector<int> &nums, int target){
    int n=nums.size();
for(int i=0;i<n;i++){
for(int j=i+1;j<n;j++){
if(nums[i]+nums[j]==target){
return{i,j};
}}}
return{};
}};





/*Sorting+two pointers
Time complexity: O(n logn)
Space complexity:O(n)*/
class solution{
public:
vector<int>twoSum(vector<int>&nums,int target){
    int n=nums.size();
//store value and index
vector<pair<int,int>>v;
for(int i=0;i<n;i++){
v.push_back({nums[i],i});
}
//sort 
sort(v.begin(),v.end());
int left=0, right=n-1;
 while(left < right){
            int sum = v[left].first + v[right].first;
            
            if(sum == target){
                return {v[left].second, v[right].second};
            }
            else if(sum < target){
                left++;
            }
            else{
                right--;
            }
        }
        
        return {};
    }
};
