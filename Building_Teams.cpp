#include<bits/stdc++.h>
using namespace std;
#define ll long long


bool dfs(ll node , vector<vector<ll>> &adj , vector<bool> &visited , ll c , vector<ll> &color) {
  visited[node] = true;
  color[node] = c;

  for(auto it : adj[node]) {
    if(!visited[it]) {
      if(dfs(it , adj , visited , 3-c , color) == true) {
        return true;
      }
    }
    else if(color[it] == color[node]){
      return true;
    }
  }
  return false;
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

  vector<bool> visited(n+1 , false);
  vector<ll> color(n+1 , -1);

  bool f = false;
  for(int i=1; i<=n; i++) {
    if(visited[i] == false) {
      if(dfs(i , adj , visited , 1 , color) == true) {
        f = true;
        break;
      }
    }
  }

  if(f) {
    cout<<"IMPOSSIBLE"<<endl;
  }
  else {
    for(int i=1; i<=n; i++) {
      cout<<color[i]<<" ";
    }
    cout<<endl;
  }
  return 0;
}