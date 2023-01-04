// pattern for finding subsequences

// fun(ind,[]){
//     if(ind>=n){
//         print([])
//         return;
//     }
//     [].add(arr[i]);
//     fun(ind+1,[]);  // case of taking element
//     [].remove(arr[i]); // backtracking
//     fun(ind+1,[]); // case of non taking element
// }
#include <bits/stdc++.h>
using namespace std;

class Subsequencies
{
public:
    vector<vector<int>> ans;
    void printSubseq(vector<int> &arr, vector<int> &ds, int index)
    {
        if (index >= arr.size())
        {
            ans.push_back(ds);
            return;
        }
        ds.push_back(arr[index]);
        printSubseq(arr, ds, index + 1);
        ds.pop_back();
        printSubseq(arr, ds, index + 1);
    }
};

int main()
{
    vector<int> arr = {3, 1, 2};
    vector<int> ds;
    Subsequencies sub;
    sub.printSubseq(arr, ds, 0);
    for (auto &vec : sub.ans)
    {
        for (int i = 0; i < vec.size(); i++)
        {
            cout << vec[i] << " ";
        }
        cout << endl;
    }
    return 0;
}

// TC : O(2^N) * N (extra N for printing).
// SC : O(N).