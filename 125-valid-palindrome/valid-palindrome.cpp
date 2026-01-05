class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0, j = s.size() - 1; // breaking the string from start and end i=0 index of sting and j= last index of sting 

        while (i < j) {
            while (i < j && !isalnum(s[i])) i++;  /* i=j string will break it works while i<j and !isalnum means the value at index
                                                                is not alphabet or number like it is a , "space" or anything then only increase i++ as soon as it is alphabet or num loop breaks  same for j  */
            while (i < j && !isalnum(s[j])) j--;

            if (tolower(s[i++]) != tolower(s[j--])) return false;
           
        }
        return true;
    }
};
