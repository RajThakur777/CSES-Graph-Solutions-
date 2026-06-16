#include<bits/stdc++.h>
using namespace std;
#define ll long long 


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

  vector<ll> dist(n+1 , LLONG_MAX);
  vector<ll> parent(n+1);

  queue<ll> q;
  q.push(1);
  dist[1] = 0;
  parent[1] = -1;

  while(!q.empty()) {
    auto it = q.front();
    q.pop();

    for(auto t : adj[it]) {
      if(dist[t] == LLONG_MAX) {
        dist[t] = dist[it] + 1;
        parent[t] = it;
        q.push(t);
      }
    }
  }

  if(dist[n] == LLONG_MAX) {
    cout<<"IMPOSSIBLE"<<endl;
  }
  else {
    cout<<dist[n] + 1<<endl;

    // for(int i=1; i<=n; i++) {
    //   cout<<parent[i]<<" ";
    // }
    // cout<<endl;

    ll val = n;
    vector<ll> arr;

    while(val != 1) {
      arr.push_back(val);
      ll p = parent[val];
      val = p;
    }

    arr.push_back(1);

    reverse(arr.begin() , arr.end());

    for(int i=0; i<arr.size(); i++) {
      cout<<arr[i]<<" ";
    }
    cout<<endl;
  }
  return 0;
}