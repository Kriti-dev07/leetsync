
class Solution {
public:
    string longestNiceSubstring(string s) {
        int n = s.size();
        string ans = "";

        for (int target = 1; target <= 26; target++) {
            int lower[26] = {0};
            int upper[26] = {0};

            int distinct = 0;
            int nice = 0;
            int left = 0;

            for (int right = 0; right < n; right++) {
                char c = s[right];
                int idx = tolower(c) - 'a';

                if (islower(c)) {
                    if (lower[idx] == 0 && upper[idx] == 0)
                        distinct++;

                    lower[idx]++;

                    if (lower[idx] == 1 && upper[idx] > 0)
                        nice++;
                } else {
                    if (upper[idx] == 0 && lower[idx] == 0)
                        distinct++;

                    upper[idx]++;

                    if (upper[idx] == 1 && lower[idx] > 0)
                        nice++;
                }

                while (distinct > target) {
                    char d = s[left++];
                    int k = tolower(d) - 'a';

                    if (islower(d)) {
                        lower[k]--;

                        if (lower[k] == 0 && upper[k] > 0)
                            nice--;

                        if (lower[k] == 0 && upper[k] == 0)
                            distinct--;
                    } else {
                        upper[k]--;

                        if (upper[k] == 0 && lower[k] > 0)
                            nice--;

                        if (upper[k] == 0 && lower[k] == 0)
                            distinct--;
                    }
                }

                if (distinct == target && nice == target) {
                    int len = right - left + 1;

                    if (len > (int)ans.size()) {
                        ans = s.substr(left, len);
                    }
                }
            }
        }

        return ans;
    }
};
