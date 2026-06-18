#include<bits/stdc++.h>
using namespace std;
#define ll long long 

void dfs(ll node , vector<vector<ll>> &revAdj , vector<bool> &visited) {
  visited[node] = true;

  for(auto it : revAdj[node]) {
    if(!visited[it]) {
      dfs(it , revAdj , visited);
    }
  }
}

int main() {
    ll n,m;
    cin>>n>>m;

    vector<vector<pair<ll , ll>>> adj(n+1);
    vector<vector<ll>> revAdj(n+1);

    for(int i=0; i<m; i++) {
        ll u,v,wt;
        cin>>u>>v>>wt;

        adj[u].push_back({v , -wt});
        revAdj[v].push_back(u);
    }

    vector<bool> visited(n+1 , false);

    dfs(n , revAdj , visited);

    vector<ll> dist(n+1 , LLONG_MAX);

    dist[1] = 0;

    for(int i=1; i<=n-1; i++) {
        bool f = false;

        for(int node=1; node<=n; node++) {
            if(dist[node] == LLONG_MAX) {
                continue;
            }

            for(auto it : adj[node]) {
                ll neigh = it.first;
                ll wt = it.second;

                if(dist[neigh] > dist[node] + wt) {
                    dist[neigh] = dist[node] + wt;
                    f = true;
                }
            }
        }
        if(!f) {
            break;
        }
    }

    bool negCycle = false;

    for(int node=1; node<=n; node++) {
        if(dist[node] == LLONG_MAX) {
            continue;
        }

        for(auto it : adj[node]) {
            ll neigh = it.first;
            ll wt = it.second;

            if(dist[neigh] > dist[node] + wt && visited[neigh] == true) {
                negCycle = true;
                break;
            }
        }
    }

    if(negCycle == true) {
      cout<<-1<<endl;
    }
    else {
      cout<<-dist[n]<<endl;
    }
    
    return 0;
}