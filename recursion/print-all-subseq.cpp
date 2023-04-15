// #include<bits/stdc++.h>
// using namespace std;
 // method 1 ---using recursion
// void findAllSubseq(string str,vector<string>&subseq,string ds,int index){
//     if(index>=str.size()){
//         if(ds.size()==0)
//         subseq.push_back("{}");
//         else
//             subseq.push_back(ds);
//         return;
//     }
//     ds += str[index];
//     findAllSubseq(str,subseq,ds,index+1);
//     ds.pop_back();
//     findAllSubseq(str,subseq,ds,index+1);
// }

// int main(){
//     string str = "abc";
//     vector<string>subseq;
//     findAllSubseq(str,subseq,"",0);
//     for(auto &s:subseq)cout<<s<<" ";
//     return 0;
// }

#include<bits/stdc++.h>
using namespace std;

void findAllSubseqIterative(string str, vector<string>& subseq) {
    int n = str.size();
    int totalSubseq = 1 << n; // 2^N
    for (int i = 0; i < totalSubseq; i++) {
        string ds = "";
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                ds += str[j];
            }
        }
        if (ds.empty()) {
            subseq.push_back("{}");
        } else {
            subseq.push_back(ds);
        }
    }
}

int main(){
    string str = "abc";
    vector<string> subseq;
    findAllSubseqIterative(str, subseq);
    for (auto &s : subseq) {
        cout << s << " ";
    }
    return 0;
}
 // have to learn bit manipulation.