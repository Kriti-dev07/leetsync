
class MajorityChecker {
private:
    struct Node {
        int candidate;
        int count;
    };

    vector<Node> tree;
    unordered_map<int, vector<int>> positions;
    int n;

    Node merge(Node a, Node b) {
        if (a.count == 0) return b;
        if (b.count == 0) return a;

        if (a.candidate == b.candidate) {
            return {a.candidate, a.count + b.count};
        }

        if (a.count > b.count) {
            return {a.candidate, a.count - b.count};
        }

        if (b.count > a.count) {
            return {b.candidate, b.count - a.count};
        }

        return {0, 0};
    }

    void build(vector<int>& arr, int node, int start, int end) {
        if (start == end) {
            tree[node] = {arr[start], 1};
            return;
        }

        int mid = start + (end - start) / 2;

        build(arr, 2 * node, start, mid);
        build(arr, 2 * node + 1, mid + 1, end);

        tree[node] = merge(tree[2 * node],
                           tree[2 * node + 1]);
    }

    Node queryTree(int node, int start, int end,
                   int left, int right) {
        if (right < start || end < left) {
            return {0, 0};
        }

        if (left <= start && end <= right) {
            return tree[node];
        }

        int mid = start + (end - start) / 2;

        Node a = queryTree(2 * node, start, mid,
                           left, right);

        Node b = queryTree(2 * node + 1, mid + 1, end,
                           left, right);

        return merge(a, b);
    }

public:
    MajorityChecker(vector<int>& arr) {
        n = arr.size();
        tree.resize(4 * n);

        for (int i = 0; i < n; i++) {
            positions[arr[i]].push_back(i);
        }

        build(arr, 1, 0, n - 1);
    }

    int query(int left, int right, int threshold) {
        Node result = queryTree(1, 0, n - 1,
                                left, right);

        int candidate = result.candidate;

        auto& idx = positions[candidate];

        int first = lower_bound(idx.begin(), idx.end(),
                                left) - idx.begin();

        int last = lower_bound(idx.begin(), idx.end(),
                               right + 1) - idx.begin();

        int frequency = last - first;

        if (frequency >= threshold) {
            return candidate;
        }

        return -1;
    }
};
