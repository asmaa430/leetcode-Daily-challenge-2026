class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto& x : edges) {
            adj[x[0]].push_back({x[1], x[2]});
            adj[x[1]].push_back({x[0], x[2] * 2});
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 0});
        unordered_set<int> visited;
        vector<int> d(n, INT_MAX);
        d[0] = 0;
        while (!pq.empty()) {
            int tp1 = pq.top().first, tp2 = pq.top().second;
            if (tp2 == n - 1) return d[tp2];
            visited.insert(tp2);
            pq.pop();
            for (auto& x : adj[tp2])
                if (visited.find(x.first) == visited.end() && x.second + d[tp2] < d[x.first]) { 
                    pq.push({d[tp2] + x.second, x.first});
                    d[x.first] = d[tp2] + x.second;
                }
        }
        return -1;
    }
};