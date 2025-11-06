class Solution {
public:
    struct DSU {
        vector<int> parent, size;
        DSU(int n) {
            parent.resize(n + 1);
            size.assign(n + 1, 1);
            iota(parent.begin(), parent.end(), 0);
        }
        int find(int x) {
            if (x == parent[x]) return x;
            return parent[x] = find(parent[x]);
        }
        void unite(int a, int b) {
            a = find(a); b = find(b);
            if (a != b) {
                if (size[a] < size[b]) swap(a, b);
                parent[b] = a;
                size[a] += size[b];
            }
        }
    };

    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        DSU dsu(c);

        // Build connections
        for (auto &e : connections) dsu.unite(e[0], e[1]);

        // Map from component -> set of online stations (sorted)
        unordered_map<int, set<int>> online;
        for (int i = 1; i <= c; i++) {
            online[dsu.find(i)].insert(i);
        }

        vector<int> res;
        vector<bool> isOnline(c + 1, true);

        for (auto &q : queries) {
            int type = q[0];
            int x = q[1];
            int comp = dsu.find(x);

            if (type == 1) {
                if (isOnline[x]) res.push_back(x);
                else {
                    if (!online[comp].empty()) res.push_back(*online[comp].begin());
                    else res.push_back(-1);
                }
            } else if (type == 2) {
                if (isOnline[x]) {
                    isOnline[x] = false;
                    online[comp].erase(x);
                }
            }
        }

        return res;
    }
};