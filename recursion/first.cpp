#include<bits/stdc++.h>
using namespace std;

class Solution{
    private:
        int fibo_sum = 0;
    public:
        int findSum(int n){                       // functional way of recursion
            if(n==0)return 0;
            else return n + findSum(n-1);
        }
        int findSum_Parameterize(int sum,int i){   // parameterize way of recursion
            if(i<1){
                cout<<"sum is"<<sum;
                return 0;
            }
            findSum_Parameterize(sum+i,i-1);
        }
        void reverseArray(vector<int>&arr,int start,int end){
            if(start>=end)return;
            int temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;
            reverseArray(arr,start+1,end-1);
        }
        int fibonachi(int n,int i,int j){
            if(n<2)return fibo_sum;
            fibo_sum +=i+j;
            fibonachi(n-1,j,i+j);
        }
};

int main(){
    // find sum of 10 numbers using recurson.
    int n = 5;
    int sum = 0;
    vector<int>arr = {12,5,7,1,3,19};
    Solution obj;
    // cout<< obj.findSum(n);
    // obj.findSum_Parameterize(sum,n);
    // obj.reverseArray(arr,0,arr.size()-1);
    // for(auto &a:arr)cout<<a<<" ";
    cout<<obj.fibonachi(n,0,1);
}
