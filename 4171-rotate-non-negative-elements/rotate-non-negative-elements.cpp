class Solution {
public:
    vector<int> rotateElements(vector<int>& nums, int k) {
        vector<int> positive;
        for(int x : nums){
            if(x>=0){
                positive.push_back(x);
                
            }
        }
        if(!positive.empty()){    
            k%=positive.size();
            std:: rotate(positive.begin(),positive.begin()+k, positive.end());
            }
            vector<int> result;
            int j=0;
            for(int x:nums){
                if(x>=0){
                    result.push_back(positive[j]);
                    j++;
                }
                else{
                    result.push_back(x);

                }
            }
            return result;
            
            
        }
    
};