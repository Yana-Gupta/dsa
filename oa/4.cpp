#include<bits/stdc++.h>

using namespace std;

const int MAX_NODES = 100000;

int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>> graph(n+1);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    vector<int> mark(n+1);
    function<void(int,int)> dfs=[&](int v,int i){
        mark[v]=i;
        for(auto u:graph[v]){
            if (mark[u]) 
                continue;
            dfs(u,i);
        }
    };

    for(int i=1;i<=n;i++){
        if(mark[i]){
            continue;
        }
        dfs(i,i);
    }
    vector<set<int>> val(n+1);
    for(int i=1;i<=n;i++){
        val[mark[i]].insert(i);
    }
    vector<int> ans;
    int q;
    cin>>q;

    while(q--){
        int t,u;
        cin>>t>>u;
        if(t==1){
            if(val[mark[u]].find(u)!=val[mark[u]].end()){
                ans.push_back(u);
            }
            else{
                if(val[mark[u]].size()){
                    ans.push_back(*val[mark[u]].begin());
                }
                else{
                    ans.push_back(-1);
                }
            }
        }
        else{
            val[mark[u]].erase(u);
        }
    }
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" \n"[i==ans.size()-1];
    }
    return 0;
}