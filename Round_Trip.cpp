#include<bits/stdc++.h>
using namespace std;
#define ll long long 

bool f = false;
vector<ll> path;

void dfs(ll node , vector<ll> &parent , ll par ,  vector<bool> &visited , vector<vector<ll>> &adj) {
  if(f) {
    return;
  }

  visited[node] = true;
  parent[node] = par;

  for(auto it : adj[node]) {
    if(f) {
      return;
    }
    if(!visited[it]) {
      dfs(it , parent , node , visited , adj);
    }
    else if(it != par) {
      f = true;
      ll start = node;
      ll dest = it;

      path.push_back(dest);

      while(start != dest) {
        path.push_back(start);
        start = parent[start];
      }

      path.push_back(dest);

      reverse(path.begin() , path.end());
    }
  }
}


int main() {
  ll n,m;
  cin>>n>>m;

  vector<vector<ll>> adj(n+1);
  for(int i=0; i<m; i++) {
    ll u,v;
    cin>>u>>v;

    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  vector<ll> parent(n+1);
  vector<bool> visited(n+1 , false);

  for(int i=1; i<=n; i++) {
    if(visited[i] == false) {
      dfs(i , parent , -1 , visited , adj);
    }
  }

  if(!f) {
    cout<<"IMPOSSIBLE"<<endl;
  }
  else {
    cout<<path.size()<<endl;
    for(int i=0; i<path.size(); i++) {
      cout<<path[i]<<" ";
    }
    cout<<endl;
  }
  return 0;
}