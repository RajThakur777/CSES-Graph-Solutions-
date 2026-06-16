#include<bits/stdc++.h>
using namespace std;
#define ll long long 

void dfs(ll node , vector<bool> &visited , vector<vector<ll>> &adj , vector<ll> &ans) {
  visited[node] = true;

  for(auto it : adj[node]) {
    if(!visited[it]) {
      dfs(it , visited , adj , ans);
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

  vector<bool> vis(n+1 , false);

  vector<ll> ans;
  for(int i=1; i<=n; i++) {
    if(vis[i] == false) {
      ans.push_back(i);
      dfs(i , vis , adj , ans);
    }
  }

  cout<<ans.size()-1<<endl;

  for(int i=0; i<ans.size()-1; i++) {
    cout<<ans[i]<<" "<<ans[i+1]<<endl;
  }
  cout<<endl;
  return 0;
}