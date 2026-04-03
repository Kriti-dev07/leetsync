class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int n = nums.size();

        // Doubly linked list
        vector<int> left(n), right(n);
        for (int i = 0; i < n; i++) {
            left[i] = i - 1;
            right[i] = (i + 1 < n ? i + 1 : -1);
        }

        // Min heap: {sum, index}
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;

        for (int i = 0; i < n - 1; i++) {
            pq.push({nums[i] + nums[i + 1], i});
        }

        vector<bool> alive(n, true);
        int ops = 0;

        // Check if sorted
        auto isSorted = [&]() {
            int prev = -1;
            for (int i = 0; i != -1; i = right[i]) {
                if (!alive[i]) continue;

                if (prev != -1 && nums[i] < nums[prev])
                    return false;

                prev = i;
            }
            return true;
        };

        while (!isSorted()) {
            auto [sum, i] = pq.top();
            pq.pop();

            int j = right[i];

            // Skip invalid structure
            if (j == -1 || !alive[i] || !alive[j]) continue;

            // ❗ CRITICAL FIX: skip stale heap entries
            if (nums[i] + nums[j] != sum) continue;

            // Merge
            nums[i] += nums[j];
            alive[j] = false;

            // Fix links
            right[i] = right[j];
            if (right[j] != -1) {
                left[right[j]] = i;
            }

            ops++;

            // Push updated adjacent pairs
            if (left[i] != -1 && alive[left[i]]) {
                pq.push({nums[left[i]] + nums[i], left[i]});
            }
            if (right[i] != -1 && alive[right[i]]) {
                pq.push({nums[i] + nums[right[i]], i});
            }
        }

        return ops;
    }
};