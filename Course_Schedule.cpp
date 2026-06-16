#include<bits/stdc++.h>
using namespace std;
#define ll long long 


int main() {
  ll n,m;
  cin>>n>>m;

  vector<vector<ll>> adj(n+1);
  vector<ll> indegree(n+1 , 0);

  for(int i=0; i<m; i++) {
    ll u,v;
    cin>>u>>v;

    adj[u].push_back(v);
    indegree[v]++;
  }

  queue<ll> q;
  vector<ll> ans;

  for(int i=1; i<=n; i++) {
    if(indegree[i] == 0) {
      q.push(i);
    }
  }

  while(!q.empty()) {
    auto it = q.front();
    q.pop();

    ans.push_back(it);

    for(auto t : adj[it]) {
      indegree[t]--;
      if(indegree[t] == 0) {
        q.push(t);
      }
    }
  }

  if(ans.size() != n) {
    cout<<"IMPOSSIBLE"<<endl;
  }
  else {
    for(auto it : ans) {
      cout<<it<<" ";
    }
    cout<<endl;
  }
  return 0;
}