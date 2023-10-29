#include<bits/stdc++.h>
using namespace std;
typedef pair<int,pair<int,int>> ipii;
const int MAX = 200000 + 1;
int N,Q,par[MAX];
stack<ipii> qList;
stack<string> ans;

// Find 연산
int doFind(int x){				
	if(x==par[x]) return x;
	return par[x]=doFind(par[x]);
}

// Union 연산
void doUnion(int a, int b){			
	a=doFind(a);
	b=doFind(b);
	if(a==b) return;
	par[a]=b;
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin>>N>>Q;
	for(int i=1;i<=N-1;i++){
		int parNode;
		cin>>parNode;
		par[i+1]=parNode;
	}
	int cnt=N-1+Q;
	while(cnt--){
		int x,b,c,d;
		cin>>x;
		if(!x) {
			cin>>b;
            
            	// 경로 삭제: first: 0 second: {자식,부모}
			qList.push({0,{b,par[b]}});	
            
            	// 경로 삭제: 부모 == 자기 자신
			par[b]=b;		   	
		}
		else{
			cin>>c>>d;
            
            	// 질의 first: 1 second: {c,d}
			qList.push({1,{c,d}});		
		}
	}
	while(!qList.empty()){
    
    		// 질의
		if(qList.top().first){			
			int c=qList.top().second.first;
			int d=qList.top().second.second;
            
            	// Find연산를 통해 연결 확인
			if(doFind(c)==doFind(d)) ans.push("YES");	
			else ans.push("NO");
		}
        
       		// 경로 삭제: Union연산을 통해 다시 연결
		else{							
			int par=qList.top().second.second;	
			int child=qList.top().second.first;
			doUnion(child,par);
		}
		qList.pop();
	}

	while(!ans.empty()){
		cout<<ans.top()<<"\n";
		ans.pop();
	}
	return 0;
}
