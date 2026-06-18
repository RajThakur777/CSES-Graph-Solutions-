#include<bits/stdc++.h>
using namespace std;
#define ll long long 

void dijitra(vector<vector<pair<ll , ll>>> &adj1 , vector<ll> &dist1 , ll node) {
  priority_queue<pair<ll , ll> , vector<pair<ll , ll>> , greater<pair<ll , ll>>> pq1;
  pq1.push({0 , node});

  while(!pq1.empty()) {
    auto it  = pq1.top();
    pq1.pop();

    ll node = it.second;
    ll d = it.first;

    if(d > dist1[node]) {
      continue;
    }

    for(auto t : adj1[node]) {
      ll neigh = t.first;
      ll dt = t.second;

      if(dist1[neigh] > dist1[node] + dt) {
        dist1[neigh] = dist1[node] + dt;
        pq1.push({dist1[node] + dt , neigh});
      }
    }
  }
}


int main() {
  ll n,m;
  cin>>n>>m;

  vector<vector<pair<ll , ll>>> adj1(n+1);
  vector<vector<pair<ll , ll>>> revAdj(n+1);
  for(int i=0; i<m; i++) {
    ll u,v,wt;
    cin>>u>>v>>wt;

    adj1[u].push_back({v , wt});
    revAdj[v].push_back({u , wt});
  }

  vector<ll> dist1(n+1 , LLONG_MAX);
  vector<ll> dist2(n+1 , LLONG_MAX);

  dist1[1] = 0;
  dist2[n] = 0;

  dijitra(adj1 , dist1 , 1);
  dijitra(revAdj , dist2 , n);

  ll ans = LLONG_MAX;

  for(int i=1; i<=n; i++) {
    ll u = i;
    
    for(auto it : adj1[u]) {
      ll v = it.first;
      ll wt = it.second;

      if(dist1[u] != LLONG_MAX && dist2[v] != LLONG_MAX) {
        ans = min(ans , dist1[u] + (wt / 2) + dist2[v]);
      }
    }
  }

  cout<<ans<<endl;
  return 0;
}