#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define MAX 1000
#define INF 100000000
using namespace std;

int result=0;
int N,P;
int out=400;
int c[MAX][MAX],f[MAX][MAX],d[MAX];
vector<int> arr[MAX];

void NF(int start,int end){
	while(1){
		fill(d,d+MAX,-1);
		queue<int> q;
		q.push(start);	
		while(!q.empty()){
			int cur=q.front(); q.pop();
			for(int i=0;i<arr[cur].size();i++){
				int next=arr[cur][i];
				if(c[cur][next]-f[cur][next]>0 && d[next]==-1){
					q.push(next);
					d[next]=cur;
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
	cin >> N >> P;
	for(int i=1;i<=N;i++){
		arr[i].push_back(i+out);
		arr[out+i].push_back(i);
		c[i][i+out]=1;
	}
	while(P--){
		int a,b; cin >> a >> b;
		arr[a+out].push_back(b);
		arr[b].push_back(a+out);
		
		arr[b+out].push_back(a);
		arr[a].push_back(b+out);
		
		c[a+out][b]=1;
		c[b+out][a]=1;
	}

	NF(401,2);
	cout << result;
	return 0;
}