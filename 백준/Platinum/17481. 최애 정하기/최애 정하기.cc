#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <cstdlib>
#include <map>
#include <queue>
#define MAX 2050
#define INF 100000000
using namespace std;

int result=0;
int N,M;
int out=1000;
map<string, int> Map;
int c[MAX][MAX],f[MAX][MAX];
vector<int> arr[MAX];


void NF(int start,int end){
	while(1){
		int d[MAX];
		fill(d,d+MAX,-1);
		queue<int> q;
		q.push(start);
		
		while(!q.empty() && d[end]==-1){
			int cur=q.front(); q.pop();
			for(int i=0;i<arr[cur].size();i++){
				int next=arr[cur][i];
				if(c[cur][next]>f[cur][next] && d[next]==-1){
					d[next]=cur;
					q.push(next);
					if(next==end) break;
				}
			}
		}
		
		if(d[end]==-1) break;
		
		int flow=INF;
		
		for(int i=end;i!=start;i=d[i]){
			flow=min(flow,c[d[i]][i]-f[d[i]][i]);
		}
		
		for(int i=end;i!=start;i=d[i]){
			f[d[i]][i]+=flow;
			f[i][d[i]]-=flow;
		}
		
		result+=flow;
		
		
		
	}
	
	
	
	
	
}


int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;
	for(int i=1;i<=M;i++){
		string s; cin >> s;
		Map[s]=i+out;
		arr[Map[s]].push_back(2010);
		arr[2010].push_back(Map[s]);
		c[Map[s]][2010]=1;
	}
	for(int i=1;i<=N;i++){
		int a; cin >> a;
		for(int j=1;j<=a;j++){
			string s; cin >> s;
			arr[i].push_back(Map[s]);
			arr[Map[s]].push_back(i);
			c[i][Map[s]]=1;
		}
		arr[0].push_back(i);
		arr[i].push_back(0);
		c[0][i]=1;
	}	
	
	NF(0,2010);
	if(result==N)
	cout << "YES";
	else{
		cout << "NO\n" << result;
	}
	return 0;
}