#include <iostream>
#include <cmath>
#include <queue>
using namespace std;

bool visit[100001];

int bfs(int start,int end){
  int depth=0,result;
  int x=0;
  queue<pair<int,int> > q;
  q.push(make_pair(start, depth));
  while(!q.empty()){
    x=q.front().first;
    depth=q.front().second;
    q.pop();
    if(x==end){
      result=depth;
      break;
    }
    if(x+1>=0 && x+1<100001 && visit[x+1]==false){
      q.push(make_pair(x+1, depth+1));
      visit[x+1]=true;
    }
    if(x-1>=0 && x-1<100001 && visit[x-1]==false){
      q.push(make_pair(x-1, depth+1));
      visit[x-1]=true;
    }
    if(x*2>=0 && x*2<100001 && visit[x*2]==false){
      q.push(make_pair(x*2, depth+1));
      visit[x*2]=true;
    }
  
  }
  return result;
}


int main(){
  int n,m;
  cin >> n >> m;
  int result=bfs(n,m);
  cout << result ;
  return 0;
}