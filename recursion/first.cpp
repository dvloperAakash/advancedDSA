#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
        int findSum(int n){
            if(n==0)return 0;
            else return n + findSum(n-1);
        }
};

int main(){
    // find sum of 10 numbers using recurson.
    int n = 10;
    int sum = 0;
    Solution obj;
    cout<< obj.findSum(n);
}
