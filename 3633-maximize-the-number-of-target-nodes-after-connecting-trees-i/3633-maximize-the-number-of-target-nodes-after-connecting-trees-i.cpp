class Solution {
public:
    vector<vector<int>> findAdj(vector<vector<int>> &edges){
        int n = edges.size();
        vector<vector<int>> adj(n+1);
        for(vector<int> edge: edges){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        return adj;
    }
    int noOfNodesWithinKEdges(vector<vector<int>> adj, int node, int k){
        queue<int> q;
        q.push(node);
        vector<bool> vis(adj.size());
        vis[node] = true;
        int dist = 0, cnt = 0;
        while(dist<=k){
            int n = q.size();
            cnt += n;
            if(dist == k)
                break;
            for(int i = 0; i<n; i++){
                int u = q.front();
                q.pop();
                for(int v: adj[u]){
                    if(!vis[v]){
                        q.push(v);
                        vis[v] = true;
                    }
                }
            }
            dist++;
        }
        return cnt;
    }
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        vector<vector<int>> adj1 = findAdj(edges1);
        vector<vector<int>> adj2 = findAdj(edges2);
        
        int n = adj1.size(), m = adj2.size();
        vector<int> nodes1;

        int maxi2 = 0;
        for(int i = 0; i<m; i++){
            maxi2 = max(maxi2, noOfNodesWithinKEdges(adj2, i, k-1));
        }


        for(int i = 0; i<n; i++){
            nodes1.push_back(noOfNodesWithinKEdges(adj1, i, k) + maxi2);
        }

        return nodes1;
    }
};