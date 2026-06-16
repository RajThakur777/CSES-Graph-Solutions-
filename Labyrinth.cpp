#include<bits/stdc++.h>
using namespace std;
#define ll long long 

//find shortest path from source to destination if it exists and also print the path in form of the string where L represents Left , R represents Right , U represents Up and D represents Down...

vector<vector<ll>> directions = {{-1 , 0} , {1 , 0} , {0 , -1} , {0 , 1}};

ll bfs(ll source_x , ll source_y , ll destination_x , ll destination_y , vector<vector<ll>> &dist , vector<vector<char>> &grid , vector<vector<pair<ll , ll>>> &parent) {
  queue<pair<ll , ll>> q;
  q.push({source_x , source_y});
  dist[source_x][source_y] = 0;

  while(!q.empty()) {
    auto it = q.front();
    q.pop();

    ll x_ = it.first;
    ll y_ = it.second;


    if(x_ == destination_x && y_ == destination_y) {
      return dist[x_][y_];
    }

    for(auto dir : directions) {
      ll new_x = x_ + dir[0];
      ll new_y = y_ + dir[1];

      if((new_x >= 0 && new_x < grid.size() && new_y >= 0 && new_y < grid[0].size() && dist[new_x][new_y] == -1 && grid[new_x][new_y] != '#')) {
        dist[new_x][new_y] = dist[x_][y_] + 1;
        parent[new_x][new_y] = {x_  , y_};
        q.push({new_x , new_y});
      }
    }
  }
  return -1;
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

  ll x1 = -1;
  ll y1 = -1;

  ll x2 = -1;
  ll y2 = -1;

  for(int i=0; i<n; i++) {
    for(int j=0; j<m; j++) {
      if(grid[i][j] == 'A') {
        x1 = i;
        y1 = j;
      }
      else if(grid[i][j] == 'B') {
        x2 = i;
        y2 = j;
      }
    }
  }

  vector<vector<ll>> dist(n , vector<ll>(m , -1));


  ll ans = bfs(x1 , y1 , x2 , y2 , dist , grid , parent);

  if(ans == -1) {
    cout<<"NO"<<endl;
  }
  else {
    vector<pair<ll , ll>> path;
    ll x = x2;
    ll y = y2;

    while(!(x == x1 && y == y1)) {
      path.push_back({x , y});

      auto p = parent[x][y];
      x = p.first;
      y = p.second;
    } 

    path.push_back({x1 , y1});

    reverse(path.begin() , path.end());

    string result;

    ll prev_x = x1;
    ll prev_y = y1;

    for(int i=1; i<path.size(); i++) {
      ll x_ = path[i].first;
      ll y_ = path[i].second;

      if((prev_x + 1) == (x_) && (prev_y == y_)) {
        result += 'D';
        prev_x = x_;
        prev_y = y_;
      }
      else if((prev_x - 1) == (x_) && (prev_y == y_)) {
        result += 'U';
        prev_x = x_;
        prev_y = y_;
      }
      else if((prev_x) == (x_) && (prev_y - 1 == y_)) {
        result += 'L';
        prev_x = x_;
        prev_y = y_;
      }
      else if((prev_x) == (x_) && (prev_y + 1 == y_)) {
        result += 'R';
        prev_x = x_;
        prev_y = y_;
      }
    }
    cout<<"YES"<<endl;
    cout<<ans<<endl;
    cout<<result<<endl;
  }
  return 0;
}