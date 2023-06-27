#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    vector<string> prior;
    for(int i=0;i<priorities.size();i++){
        string s="";
        s+=(char)(priorities[i])+48;
        s+=((char)i)+48;
        prior.push_back(s);
    }
    int psize=priorities.size();
    bool flag=false;
    vector<string> result;
    while(result.size()!=psize){
        flag=false;
        string now=prior[0];
        prior.erase(prior.begin());
        for(int i=0;i<psize;i++){
            if(now[0]<prior[i][0]){
                flag=true;
                break;
            }
        }
        if(flag){
            prior.push_back(now);
        }else{
            result.push_back(now);
        }
    }
    
    for(int i=0;i<result.size();i++){
        if(result[i][1]-48==location)
            return i+1;
    }
}