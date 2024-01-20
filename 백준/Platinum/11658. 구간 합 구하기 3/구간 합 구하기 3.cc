#include <iostream>
#define MAX 1025
using namespace std;

int n,k,q;
int arr[MAX][MAX],seg[MAX][MAX];

void update(int x,int y,int val){
	for(int i=y;i<=n;i+=(i&-i)){
		for(int j=x;j<=n;j+=(j&-j)){
			seg[i][j]+=val;
		}
	}
}

long long _query(int x,int y){
	long long ans=0;
	for(int i=y;i>0;i-=(i&-i)){
		for(int j=x;j>0;j-=(j&-j)){
			ans+=seg[i][j];
		}
	}
	return ans;
}

long long query(int x1,int y1,int x2,int y2){
	return _query(x2,y2)-_query(x1-1,y2)-_query(x2,y1-1)+_query(x1-1,y1-1);	
}

int main(){
	ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> q;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin >> arr[i][j];
			update(i,j,arr[i][j]);
		}
	}

	while(q--){
		int com,a,b,c,d; cin >> com;
		if(com==0){
			cin >> a >> b >> c;
			update(a,b,c-arr[a][b]);
			arr[a][b]=c;
		}else{
			cin >> a >> b >> c >> d;
			cout << query(a,b,c,d) << '\n';
		}
	}
	
	
		
	return 0;
}


