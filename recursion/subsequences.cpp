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
private:
    int targetSum = 8;

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
    void printTargetSum(vector<int> &arr, int sum, vector<int> ds, int index)
    {
        if (index >= arr.size())
        {
            if (sum == targetSum)
            {
                ans.push_back(ds);
            }
            return;
        }
        ds.push_back(arr[index]);
        sum += arr[index];
        printTargetSum(arr, sum, ds, index + 1);
        ds.pop_back();
        sum -= arr[index];
        printTargetSum(arr, sum, ds, index + 1);
    }

    bool printOnlyOneTargetSum(vector<int> &arr, int sum, vector<int> ds, int index)
    {
        if (index >= arr.size())
        {
            if (sum == targetSum)
            {
                ans.push_back(ds);
                return true;
            }
            return false;
        }
        ds.push_back(arr[index]);
        sum += arr[index];
        if (printOnlyOneTargetSum(arr, sum, ds, index + 1) == true)
            return true;
        ds.pop_back();
        sum -= arr[index];
        if (printOnlyOneTargetSum(arr, sum, ds, index + 1) == true)
            return true;
        return false;
    }
    int countSubsequencies(vector<int> &arr, int index, int sum)
    {
        if (index >= arr.size())
        {
            if (sum == targetSum)
                return 1;
            else
                return 0;
        }

        sum += arr[index];
        int pick = countSubsequencies(arr, index + 1, sum);
        sum -= arr[index];
        int notPick = countSubsequencies(arr, index + 1, sum);
        return pick + notPick;
    }
};

int main()
{
    vector<int> arr = {3, 1, 2, 5, 4};
    vector<int> ds;
    Subsequencies sub;
    // sub.printSubseq(arr, ds, 0);
    // sub.printTargetSum(arr,0,ds,0);
    // sub.printOnlyOneTargetSum(arr, 0, ds, 0);
    cout << sub.countSubsequencies(arr, 0, 0);
    // for (auto &vec : sub.ans)
    // {
    //     for (int i = 0; i < vec.size(); i++)
    //     {
    //         cout << vec[i] << " ";
    //     }
    //     cout << endl;
    // }
    return 0;
}

// TC : O(2^N) * N (extra N for printing).
// SC : O(N).