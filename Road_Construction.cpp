#include<bits/stdc++.h>
using namespace std;
#define ll long long 

//DSU Using size
vector<ll> parent;
vector<ll> Size;

ll maxi = 0;

ll find_parent(ll x) {
  if(parent[x] == x) {
    return x;
  }

  return parent[x] = find_parent(parent[x]);
}

void Union(ll x , ll y) {
  ll px = find_parent(x);
  ll py = find_parent(y);

  if(px == py) {
    return;
  }

  if(Size[px] < Size[py]) {
    parent[px] = py;
    Size[py] += Size[px];

    maxi = max(maxi , Size[py]);
  }
  else {
    parent[py] = px;
    Size[px] += Size[py];

    maxi = max(maxi , Size[px]);
  }
}


int main() {
  ll n,m;
  cin>>n>>m;

  parent.resize(n+1);
  Size.resize(n+1 , 1);

  for(int i=1; i<=n; i++) {
    parent[i] = i;
  }

  ll components = n;

  for(int i=0; i<m; i++) {
    ll u,v;
    cin>>u>>v;

    ll pu = find_parent(u);
    ll pv = find_parent(v);

    if(pu == pv) {
      cout<<components<<" "<<maxi<<endl;
    }
    else {
      Union(pu , pv);
      components--;

      cout<<components<<" "<<maxi<<endl;
    }
  }
  return 0;
}