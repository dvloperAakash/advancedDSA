class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        string str = "";
        int len = 0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(text1[i-1]==text2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }else{
                    dp[i][j] = 0 + max(dp[i-1][j],dp[i][j-1]);
                }
            // len = max(len,dp[i][j]);
            }
        }
         len = dp[n][m];
        vector<char>ans(len);
        
        int i = n;
        int j = m;

        while(i>=0 && j>=0 && len>0){
            if(text1[i-1]==text2[j-1]){
                ans[--len] = text1[i-1];
                i--;
                j--;
            }else{
                if(dp[i-1][j]>dp[i][j-1]){
                    i--;
                }else{
                    j--;
                }
                if(text1[i-1]==text2[j-1]){
                    ans[--len] = text1[i-1];
                    i--;
                    j--;
                }
            }
        }
    for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
    return dp[n][m];
    // tc for printing lcs is O(N+M) and sc : O(N*M)
    }
};
