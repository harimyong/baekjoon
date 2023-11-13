#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h> 
#include <queue>
#define MAX 810
#define INF 100000000
using namespace std;

int N,M;
int out=400;
vector<int> arr[MAX];
int work_cnt=0;
int result=0;
int d[MAX];
int cost[MAX][MAX]={0,};
int c[MAX][MAX],f[MAX][MAX];
void NF(int start,int end){
	while(1){
		int dist[MAX];
		bool visit[MAX];
		fill(d,d+MAX,-1);
		fill(dist,dist+MAX,INF);
		fill(visit,visit+MAX,false);
		queue<int> q;
		q.push(start);	
		visit[start]=true;
		dist[start]=0;
		d[start]=start;
		while(!q.empty()){
			int cur=q.front(); q.pop();
			visit[cur]=false;
			for(int i=0;i<arr[cur].size();i++){
				int next=arr[cur][i];
				if(c[cur][next]-f[cur][next]>0 && dist[next]>dist[cur]+cost[cur][next]){
					dist[next]=dist[cur]+cost[cur][next];
					d[next]=cur;
					if(!visit[next]){
						visit[next]=true;
						q.push(next);
					}
				}
			}
		}
		
		if(d[end]==-1) break;
		
		int flow=INF;
		
		for(int i=end;i!=start;i=d[i]){
			flow=min(flow,c[d[i]][i]-f[d[i]][i]);
		}
		
		for(int i=end;i!=start;i=d[i]){
			work_cnt-=cost[d[i]][i]*flow;
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
	
	for(int i=1;i<=N;i++){
		arr[0].push_back(i);
		arr[i].push_back(0);
		c[0][i]=1;
	}
	
	for(int i=1;i<=N;i++){
		int cnt; cin >> cnt;
		while(cnt--){
			int num,pay;
			cin >> num >> pay;
			arr[i].push_back(num+out);
			arr[num+out].push_back(i);
			cost[i][num+out]=-pay;
			cost[num+out][i]=pay;
			c[i][num+out]=1;
		}
	}
	
	for(int i=1;i<=M;i++){
		arr[805].push_back(i+out);
		arr[i+out].push_back(805);
		c[i+out][805]=1;
	}
	
	NF(0,805);
	cout << result << '\n' << work_cnt << '\n';
	return 0;
}