class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int count1 = 0, count2 = 0;
        int cand1 = 0, cand2 = 1;

        // Find candidates
        for (int num : nums) {
            if (num == cand1) {
                count1++;                                 
            }
            else if (num == cand2) {              // this is just increasing the frequency some different number comes other than cand1 or cand2 then the condition will shift to the else count1-- and count2--
                count2++;
            }
            else if (count1 == 0) {        // if all the votes has been cancelled out then i am open to get a new candidate 
                cand1 = num;
                count1 = 1;
            }
            else if (count2 == 0) {
                cand2 = num;
                count2 = 1;                  // same as above 
            }
            else {
                count1--;
                count2--;                 //if both are different both will be decreted as their votes will be cancelled 
            } // and as soon as any count 1 or count 2 is = 0 after decrement count 1==0 or count 2==0 condition will get executed 
        }




      //count the frequency 
        count1 = count2 = 0;
        for (int num : nums) {          // this thing iterated through the whole array to know the real frequency of candidates propects found through the above part 
            if (num == cand1) count1++;
            else if (num == cand2) count2++;
        }
                // final check if these things satisfy the n/3 condition 
        vector<int> result;
        if (count1 > nums.size() / 3) result.push_back(cand1);
        if (count2 > nums.size() / 3) result.push_back(cand2);

        return result;
    }
};
