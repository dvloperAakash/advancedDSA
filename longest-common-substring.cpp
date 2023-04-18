class Solution{
    public:
        int longestCommonSubstr (string s1, string s2, int n, int m)
        {
            int ans = 0;
            vector<vector<int>>dp(3,vector<int>(m+1,0));
            for(int i=1;i<=n;i++){
                for(int j=1;j<=m;j++){
                    if(s1[i-1]==s2[j-1]){
                        if(i-2>=0 && j-2>=0 && s1[i-2]==s2[j-2]){
                            dp[i][j] = 1 + dp[i-1][j-1];
                        }else{
                            dp[i][j] = 1;
                        }
                    }
                ans = max(ans,dp[i][j]);
                }
            }
        return ans;
        }
};

//{ Driver Code Starts.

{
    int t; cin >> t;
    while (t--)
    {
        int n, m; cin >> n >> m;
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr (s1, s2, n, m) << endl;
    }
}
// tc : O(N*M)
//SC : O(N*M) can be optimised to O(2*M) .I have to do this .
