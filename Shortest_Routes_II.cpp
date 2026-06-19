#include<bits/stdc++.h>
using namespace std;
#define ll long long 


int main() {
  ll n,m,q;
  cin>>n>>m>>q;

  vector<vector<ll>> dist(n+1 , vector<ll>(n+1 , LLONG_MAX));

  for(int i=0; i<m; i++) {
    ll u,v,wt;
    cin>>u>>v>>wt;

    dist[u][v] = min(dist[u][v] , wt);
    dist[v][u] = min(dist[v][u] , wt);
  }

  for(int i=1; i<=n; i++) {
    dist[i][i] = 0;
  }

  for(int via=1; via<=n; via++) {
    for(int i=1; i<=n; i++) {
      for(int j=1; j<=n; j++) {
        if(dist[i][via] != LLONG_MAX && dist[via][j] != LLONG_MAX) {
          dist[i][j] = min(dist[i][j] , dist[i][via] + dist[via][j]);
        }
      }
    }
  }

  while(q--) {
    ll u,v;
    cin>>u>>v;

    if(dist[u][v] == LLONG_MAX) {
      cout<<-1<<endl;
    }
    else {
      cout<<dist[u][v]<<endl;
    }
  }
  return 0;
}