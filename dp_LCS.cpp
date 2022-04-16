#include<bits/stdc++.h>
using namespace std;

//using recursion
// int lcs(string x, string y, int n, int m) {
//     //base condition
//     if( n == 0 || m == 0)
//        return 0;
//     //choice diagram
//     if( x[n-1] == y[m-1])
//        return 1 + lcs(x,y,n-1,m-1);
//     else
//        return max(lcs(x,y,n-1,m), lcs(x,y,n,m-1));
// }

//top down --memoization
// int dp[1001][1001];
// int lcs(string x, string y, int n, int m) {
//     //base condition
//     if( n == 0 || m == 0)
//        return dp[n][m] = 0;
//     //dp call
//     if( dp[n][m] != -1)
//        return dp[n][m];
//     //choice diagram
//     if( x[n-1] == y[m-1])
//        return dp[n][m] = 1 + lcs(x,y,n-1,m-1);
//     else
//        return dp[n][m] = max(lcs(x,y,n-1,m), lcs(x,y,n,m-1));
// }

// bottom up approach -- tabulation
int lcs(string x, string y, int n, int m) {
    int dp[n + 1][ m + 1];

    for(int i = 0; i < n + 1; ++i)
        for(int j = 0; j < m + 1; ++j) {
            if( i == 0 || j == 0)
                dp[i][j] = 0;
            else if ( x[i-1] == y[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }

   return dp[n][m];
}




int main() {
   // memset(dp,-1,sizeof(dp));
    string s1 = "AGGTAB";
    string s2 = "GXTXAYB";
    int n = s1.size(); 
    int m = s2.size();

    cout << lcs(s1,s2,n,m);
}