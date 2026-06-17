#include<bits/stdc++.h>
using namespace std;
#define ll long long 

vector<vector<ll>> directions = {{-1 , 0} , {1 , 0} , {0 , -1} , {0 , 1}};

bool solve(ll x , ll y , ll n , ll m) {
    if((y == m-1 || y == 0)) {
        return true;
    }

    if((x == n-1 || x == 0)) {
        return true;
    }
    return false;
}

int main() {
  ll n,m;
  cin>>n>>m;

  vector<vector<char>> grid(n , vector<char>(m));
  for(int i=0; i<n; i++) {
    for(int j=0; j<m; j++) {
      cin>>grid[i][j];
    }
  }

  vector<vector<pair<ll , ll>>> parent(n , vector<pair<ll , ll>>(m , {-1 , -1}));

  vector<vector<ll>> dist1(n, vector<ll>(m, LLONG_MAX));
  queue<pair<ll , ll>> q1;

  for(int i=0; i<n; i++) {
    for(int j=0; j<m; j++) {
      if(grid[i][j] == 'M') {
        q1.push({i , j});
        dist1[i][j] = 0;
      }
    }
  }

  while(!q1.empty()) {
    auto it = q1.front();
    q1.pop();

    ll x_ = it.first;
    ll y_ = it.second;

    for(auto dir : directions) {
      ll new_x = x_ + dir[0];
      ll new_y = y_ + dir[1];

      if((new_x >= 0 && new_x < n && new_y >= 0 && new_y < m && dist1[new_x][new_y] == LLONG_MAX && grid[new_x][new_y] != '#')) {
        dist1[new_x][new_y] = 1 + dist1[x_][y_];
        q1.push({new_x , new_y});
      }
    }
  }

  queue<pair<ll,ll>> q2;
vector<vector<ll>> dist2(n, vector<ll>(m, LLONG_MAX));

ll source_x = -1;
ll source_y = -1;

for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        if(grid[i][j]=='A'){
            source_x=i;
            source_y=j;
            q2.push({i,j});
            dist2[i][j]=0;
        }
    }
}

if(solve(source_x, source_y, n, m)){
    cout<<"YES\n";
    cout<<0<<"\n";
    return 0;
}

bool f = false;
ll x1 = -1;
ll y1 = -1;

while(!q2.empty()){
    auto it = q2.front();
    q2.pop();

    ll x_ = it.first;
    ll y_ = it.second;

    if(solve(x_, y_, n, m)){
        f = true;
        x1 = x_;
        y1 = y_;
        break;
    }

    for(auto dir : directions){
        ll new_x = x_ + dir[0];
        ll new_y = y_ + dir[1];

        if(new_x >= 0 && new_x < n &&
           new_y >= 0 && new_y < m &&
           grid[new_x][new_y] != '#' &&
           dist2[new_x][new_y] == LLONG_MAX &&
           dist2[x_][y_] + 1 < dist1[new_x][new_y])
        {
            dist2[new_x][new_y] = dist2[x_][y_] + 1;
            parent[new_x][new_y] = {x_, y_};
            q2.push({new_x, new_y});
        }
    }
}

if(!f){
    cout<<"NO\n";
    return 0;
}

cout<<"YES\n";
cout<<dist2[x1][y1]<<"\n";

vector<pair<ll,ll>> path;

ll prev_x = x1;
ll prev_y = y1;

while(!(prev_x == -1 && prev_y == -1)){
    path.push_back({prev_x, prev_y});

    auto p = parent[prev_x][prev_y];

    prev_x = p.first;
    prev_y = p.second;
}

reverse(path.begin(), path.end());

string res = "";

ll t1 = path[0].first;
ll t2 = path[0].second;

for(int i=1;i<(int)path.size();i++){
    ll t3 = path[i].first;
    ll t4 = path[i].second;

    if(t1 + 1 == t3 && t2 == t4) res += 'D';
    else if(t1 - 1 == t3 && t2 == t4) res += 'U';
    else if(t1 == t3 && t2 - 1 == t4) res += 'L';
    else if(t1 == t3 && t2 + 1 == t4) res += 'R';

    t1 = t3;
    t2 = t4;
}

cout<<res<<"\n";
  return 0;
}