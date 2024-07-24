#include<bits/stdc++.h>

using namespace std;

bool isCycle( int parent, int node, vector<vector<int>>& graph, vector<bool>& vis) {
    vis[node] = 1;
 
    for ( auto n: graph[node] ) {
        if ( vis[n] ) {
            if ( n != parent ) 
                return true;
        }
        else {
            if ( isCycle(node, n, graph, vis)) return true;
        }
    }

    return false;
}

int main () {

    vector<vector<int>> graph(5);

    graph[0] = {1};
    graph[1] = {0, 4};
    graph[2] = {3};
    graph[3] = {2};
    graph[4] = {1};
    vector<bool> vis(5, false);

    for ( auto i = 0; i < 5; i++ ) {
        if ( !vis[i] && isCycle(-1, i, graph, vis) ) {
            cout << 1 << endl;
            return 0;
        }
    }
    cout << 0 << endl;

    return 0;
}


/**
 * 0 - > 1 -> 4 -> 2
 * 2 -> 3 
 * 
 * 
 * **/