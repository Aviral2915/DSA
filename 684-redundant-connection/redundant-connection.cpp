class Solution {
public:
   
   bool dfs(int node,int target, vector<vector<int>> &adj,vector<int> & vis){
    if(node==target) return true;
    vis[node]=1;

    for(int neigh:adj[node]){
        if(!vis[neigh]){
            if(dfs(neigh,target,adj,vis)){
                return true;
            }
        }
    }
    return false;
   }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {

        int n=edges.size();
        vector<vector<int>> adj(n+1);

        for(auto &e: edges){
            int u=e[0];
            int v=e[1];

            vector<int> vis(n+1,0);

            if(!adj[u].empty() && !adj[v].empty()&& dfs(u,v,adj,vis)){
                return{u,v};
            }

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        return{};
        
    }
};