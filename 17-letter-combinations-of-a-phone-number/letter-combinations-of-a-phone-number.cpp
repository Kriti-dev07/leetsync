class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};

        vector<string> map = {
            "", "", "abc", "def",
            "ghi", "jkl", "mno",
            "pqrs", "tuv", "wxyz"
        };

        vector<string> ans;
        string curr;

        solve(0, digits, map, curr, ans);
        return ans;
    }

private:
    void solve(int i, string &digits, vector<string> &map,
               string &curr, vector<string> &ans) {

        if (i == digits.size()) {
            ans.push_back(curr);
            return;
        }

        string &letters = map[digits[i] - '0'];

        for (char c : letters) {
            curr.push_back(c);
            solve(i + 1, digits, map, curr, ans);
            curr.pop_back();   // backtrack
        }
    }
};