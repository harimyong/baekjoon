#include <iostream>
#include <queue>
#include <vector>
using namespace std;



int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	priority_queue<int,vector<int>,greater<int> > pq_p;
	priority_queue<int,vector<int>,less<int> > pq_m;
	int n;
	cin >> n;
	for(int i=0;i<n;i++){
		int a;
		cin >> a;
		if(a>0)
		pq_p.push(a);
		else if(a<0)
		pq_m.push(a);
		else{
			if((pq_p.empty()) && (pq_m.empty())){
				cout << "0\n";
			}
			else if(pq_p.empty()){
				cout << pq_m.top() <<'\n';
				pq_m.pop();
			}
			else if(pq_m.empty()){
				cout << pq_p.top() <<'\n';
				pq_p.pop();
			}else{
				if(pq_p.top()<-pq_m.top()){
					cout << pq_p.top() <<'\n';	
					pq_p.pop();	
				}
				else if(pq_p.top()>-pq_m.top()){
					cout << pq_m.top() <<'\n';	
					pq_m.pop();	
				}else{
					cout << pq_m.top() <<'\n';	
					pq_m.pop();	
				}
			}
		}
	}	
	
	
	return 0;
}