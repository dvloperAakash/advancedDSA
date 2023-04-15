#include<bits/stdc++.h>
using namespace std;

void findAllSubseq(string str,vector<string>&subseq,string ds,int index){
    if(index>=str.size()){
        if(ds.size()==0)
        subseq.push_back("{}");
        else
            subseq.push_back(ds);
        return;
    }
    ds += str[index];
    findAllSubseq(str,subseq,ds,index+1);
    ds.pop_back();
    findAllSubseq(str,subseq,ds,index+1);
}

int main(){
    string str = "abc";
    vector<string>subseq;
    findAllSubseq(str,subseq,"",0);
    for(auto &s:subseq)cout<<s<<" ";
    return 0;
}