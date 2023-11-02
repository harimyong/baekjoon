#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <string>
using namespace std;

int main(){
	vector<string> result;
	while(1){
		vector<char> v;
		string s;
		getline(cin,s);
		if(s=="."){
			break;
		}
		string res="yes";
		for(int i=0;i<s.length();i++){
			if(v.empty()){
				if(s[i]==')' || s[i]==']'){
					res="no";
					break;
				}
				else if(s[i]=='(' || s[i]=='['){
					v.push_back(s[i]);
				}
			}
			else{
				if(s[i]==')' && v.back()!='('){
					res="no";
					break;
				}
				else if(s[i]==']' && v.back()!='['){
					res="no";
					break;
				}
				else if(s[i]==')' && v.back()=='('){
					v.pop_back();
				}
				else if(s[i]==']' && v.back()=='['){
					v.pop_back();
				}
				else if(s[i]=='[' || s[i]=='('){
					v.push_back(s[i]);
				}
			}
		
		}
		
	
		
		if(res=="no" || v.size()!=0){
			result.push_back("no");
		}
		else if(res=="yes"){
			result.push_back("yes");
		}
		
		
	
	}
	
	for(int i=0;i<result.size();i++){
			cout << result[i] << '\n';
		}
	
		
	
	return 0;
}