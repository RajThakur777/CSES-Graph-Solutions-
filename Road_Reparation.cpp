#include<bits/stdc++.h>
using namespace std;
#define ll long long 

vector<ll> parent;
vector<ll> rk;

ll find_parent(ll x) {
  if(x == parent[x]) {
    return x;
  }

  return parent[x] = find_parent(parent[x]);
}

void Union(ll x , ll y) {
  ll p_x = find_parent(x);
  ll p_y = find_parent(y);

  if(p_x == p_y) {
    return;
  }

  if(rk[p_x] < rk[p_y]) {
    parent[p_x] = p_y;
  }
  else if(rk[p_y] < rk[p_x]){
    parent[p_y] = p_x;
  }
  else {
    parent[p_y] = p_x;
    rk[p_x]++;
  }
}

//finding MST using kruskal algo

bool cmp(vector<ll> &a , vector<ll> &b) {
  return (a[2] < b[2]);
}

int main() {
  ll n,m;
  cin>>n>>m;

  parent.resize(n+1);
  rk.resize(n+1);

  for(int i=1; i<=n; i++) {
    parent[i] = i;
  }

  vector<vector<ll>> adj;
  for(int i=0; i<m; i++) {
    ll u,v,wt;
    cin>>u>>v>>wt;

    adj.push_back({u , v , wt});
  }

  sort(adj.begin() , adj.end() , cmp);

  ll cost = 0;
  ll cnt = 0;

  for(auto &edge : adj) {
    ll u = edge[0];
    ll v = edge[1];
    ll c = edge[2];

    if(find_parent(u) != find_parent(v)) {
        cost += c;
        Union(u, v);
        cnt++;
    }
  }

  if(cnt != (n - 1)) {
    cout<<"IMPOSSIBLE"<<endl;
  }
  else {
    cout<<cost<<endl;
  }
  return 0;
}