#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
        int findSum(int n){                       // funfctional way of recursion
            if(n==0)return 0;
            else return n + findSum(n-1);
        }
        int findSum_Parameterize(int sum,int i){
            if(i<1){
                cout<<"sum is"<<sum;
                return 0;
            }
            findSum_Parameterize(sum+i,i-1);
        }
};

int main(){
    // find sum of 10 numbers using recurson.
    int n = 5;
    int sum = 0;
    Solution obj;
    // cout<< obj.findSum(n);
    obj.findSum_Parameterize(sum,n);
}
