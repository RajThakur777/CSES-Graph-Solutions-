#include<bits/stdc++.h>
using namespace std;
#define ll long long 


void dfs(ll i , ll j , vector<vector<char>> &grid) {
  if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == '#') {
    return;
  }

  grid[i][j] = '#';

  dfs(i+1 , j , grid);
  dfs(i-1 , j , grid);
  dfs(i , j+1 , grid);
  dfs(i , j-1 , grid);
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

  ll cnt = 0;

  for(int i=0; i<n; i++) {
    for(int j=0; j<m; j++) {
      if(grid[i][j] == '.') {
        cnt++;
        dfs(i , j , grid);
      }
    }
  }

  cout<<cnt<<endl;
  return 0;
}