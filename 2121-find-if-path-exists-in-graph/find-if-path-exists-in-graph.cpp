class Solution {
public:

    bool dfs(int node,int target, vector<vector<int>> &adj,vector<int>&vis){
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
     
    bool validPath(int n, vector<vector<int>>& edges, int source, int target){

        if(source==target) return true;
        vector<vector<int>> adj(n);

        for(auto &e:edges){
            int u=e[0];
            int v=e[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> vis(n,0);

        return dfs(source,target,adj,vis);
        
    }
};