#include<bits/stdc++.h>
using namespace std;
#define ll long long 


int main() {
  ll n,m;
  cin>>n>>m;

  vector<vector<pair<ll , ll>>> vec(n+1);
  for(int i=0; i<m; i++) {
    ll u,v,wt;
    cin>>u>>v>>wt;

    vec[u].push_back({v , wt});
  }

  vector<ll> dist(n+1 , LLONG_MAX);

  priority_queue<pair<ll , ll> , vector<pair<ll , ll>> , greater<pair<ll , ll>>> pq;
  pq.push({0 , 1});

  dist[1] = 0;

  while(!pq.empty()) {
    auto it = pq.top();
    pq.pop();

    ll node = it.second;
    ll d = it.first;

    if(d > dist[node]) {
      continue;
    }

    for(auto t : vec[node]) {
      ll neigh = t.first;
      ll dt = t.second;

      if(dist[neigh] > dist[node] + dt) {
        dist[neigh] = dist[node] + dt;
        pq.push({dist[node] + dt , neigh});
      }
    }
  }

  for(int i=1; i<=n; i++) {
    cout<<dist[i]<<" ";
  }
  cout<<endl;
  return 0;
}