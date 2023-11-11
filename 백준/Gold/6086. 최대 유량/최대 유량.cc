#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define MAX 705
#define INF 100000000
using namespace std;

int result=0;
int N,M,K;
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
	cin >> N;
	while(N--){
		char a,b;
		int num;
		cin >> a >> b >> num;
		arr[(int)a].push_back((int)b);
		arr[(int)b].push_back((int)a);
		c[(int)a][(int)b]+=num;
		c[(int)b][(int)a]+=num;				
	}
	NF((int)'A',(int)'Z');
	cout << result;
	return 0;
}