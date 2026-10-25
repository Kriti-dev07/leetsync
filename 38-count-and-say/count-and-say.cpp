
class Solution {
public:
    string countAndSay(int n) {
        string s = "1";
  for (int k = 2; k <= n; k++) {
            string ans = "";
            int i = 0;

         while (i < s.size()) {
                int j = i;

                while (j < s.size() && s[j] == s[i]) {
                    j++;
                }

                ans += to_string(j - i);
                ans += s[i];

                i = j;
            }

            s = ans;
        }

        return s;
    }
};
