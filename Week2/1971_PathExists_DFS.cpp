class Solution {
public:
    vector<int> parent;

   
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        parent.resize(n);
        for (int i = 0; i < n; ++i)
            parent[i] = i;

        for (auto& edge : edges)
            unionSet(find(edge[0]), find(edge[1]));

      
        return find(source) == find(destination);
    }

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void unionSet(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
      
        if (rootX != rootY)
            parent[rootX] = rootY;
    }
};
