class Solution {
public:
    int firstUniqueEven(vector<int>& nums) {
        unordered_map<int,int> hello;
        for(int x:nums){
            hello[x]++;
        }
        for(int a:nums){
            if(hello[a]==1 && a%2==0 ){
                return a;
            }
           

        }
         return -1;
    }
};