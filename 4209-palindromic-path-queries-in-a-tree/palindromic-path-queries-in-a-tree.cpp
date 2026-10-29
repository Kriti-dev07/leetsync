
class Solution {
    int n, LOG, timer;
    vector<vector<int>> adj, up;
    vector<int> depth, tin, tout, pref, bit, nodeMask;

    void add(int i, int val) {
        while (i <= n) {
            bit[i] ^= val;
            i += i & -i;
        }
    }

    void rangeXor(int l, int r, int val) {
        if (val == 0) return;

        add(l, val);
        if (r + 1 <= n)
            add(r + 1, val);
    }

    int pointQuery(int i) {
        int res = 0;

        while (i > 0) {
            res ^= bit[i];
            i -= i & -i;
        }

        return res;
    }

    int lca(int a, int b) {
        if (depth[a] < depth[b])
            swap(a, b);

        int diff = depth[a] - depth[b];

        for (int k = 0; k < LOG; k++) {
            if ((diff >> k) & 1)
                a = up[k][a];
        }

        if (a == b) return a;

        for (int k = LOG - 1; k >= 0; k--) {
            if (up[k][a] != up[k][b]) {
                a = up[k][a];
                b = up[k][b];
            }
        }

        return up[0][a];
    }

public:
    vector<bool> palindromePath(int n, vector<vector<int>>& edges,
                                string s, vector<string>& queries) {
        this->n = n;
        timer = 0;

        LOG = 1;
        while ((1 << LOG) <= n)
            LOG++;

        adj.assign(n, {});
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        depth.assign(n, 0);
        tin.assign(n, 0);
        tout.assign(n, 0);
        pref.assign(n, 0);
        nodeMask.assign(n, 0);
        up.assign(LOG, vector<int>(n, 0));
        bit.assign(n + 2, 0);

        for (int i = 0; i < n; i++)
            nodeMask[i] = 1 << (s[i] - 'a');

        // Iterative DFS: find subtree ranges and root prefixes
        vector<int> parent(n, 0), it(n, 0), st;
        st.push_back(0);

        tin[0] = ++timer;
        pref[0] = nodeMask[0];
        up[0][0] = 0;

        while (!st.empty()) {
            int u = st.back();

            if (it[u] < (int)adj[u].size()) {
                int v = adj[u][it[u]++];

                if (v == parent[u])
                    continue;

                parent[v] = u;
                depth[v] = depth[u] + 1;
                up[0][v] = u;
                pref[v] = pref[u] ^ nodeMask[v];
                tin[v] = ++timer;

                st.push_back(v);
            } else {
                tout[u] = timer;
                st.pop_back();
            }
        }

        // Binary lifting table
        for (int k = 1; k < LOG; k++) {
            for (int u = 0; u < n; u++) {
                up[k][u] = up[k - 1][up[k - 1][u]];
            }
        }

        vector<bool> ans;

        for (string &q : queries) {
            string op;
            int u, v;
            char c;

            stringstream ss(q);
            ss >> op >> u;

            if (op == "update") {
                ss >> c;

                int newMask = 1 << (c - 'a');
                int change = nodeMask[u] ^ newMask;

                // Changing u affects every prefix in its subtree
                rangeXor(tin[u], tout[u], change);
                nodeMask[u] = newMask;
            } else {
                ss >> v;

                int ancestor = lca(u, v);

                int pu = pref[u] ^ pointQuery(tin[u]);
                int pv = pref[v] ^ pointQuery(tin[v]);

                int pathMask = pu ^ pv ^ nodeMask[ancestor];

                // At most one odd-frequency character
                ans.push_back((pathMask & (pathMask - 1)) == 0);
            }
        }

        return ans;
    }
};
