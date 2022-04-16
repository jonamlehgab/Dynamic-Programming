#include<bits/stdc++.h>
using namespace std;

//using recursion
// int maxProfit(vector<int> &wt, vector<int> &val, int W, int n) {
//     // if bag capacity is zero or either price is zero then maxProfit is zero
//     if(W == 0 || n == 0)
//        return 0;
//     // if current weight is under the bag capacity then there are two choices either to include or not
//     if(wt[n-1] <= W)
//       return max(val[n-1] + maxProfit(wt,val,W-wt[n-1],n - 1), maxProfit(wt,val,W, n - 1));
//     // if current wight is larger than bag capacity then discard it
//     else if(wt[n-1] > W)
//       return maxProfit(wt,val,W,n-1);
// }

/// top down approach : memoization
//int dp[100][100];
// int maxProfit(vector<int> &wt, vector<int> &val, int W, int n) {
//     //base condition
//     if( W == 0 || n == 0)
//        return dp[n][W] = 0;
//     // if we have seen dp result then we simply return it
//     if(dp[n][W] != -1)
//        return dp[n][W];
//     //choice diagram
//     if(wt[n-1]<=W)
//      return dp[n][W] = max(val[n-1] + maxProfit(wt,val,W-wt[n-1],n-1), maxProfit(wt,val,W,n-1));

//     else if(wt[n] > W)
//      return dp[n][W] = maxProfit(wt,val,W,n-1);
// }

//using bottom approach : tabulation
int maxProfit(vector<int> &wt, vector<int> &val, int W, int n) {
    int dp[n+1][W+1];
    memset(dp,-1,sizeof(dp));

    for(int i = 0; i <n+1; ++i) {
        for(int j = 0; j <W + 1; ++j) {
            // base condition
            if(i==0 || j==0)
              dp[i][j] = 0;

           else if(wt[i-1] <= j)
              dp[i][j] = max( val[i-1] + dp[i-1][j-wt[i-1]], dp[i-1][j] )  ;

            else 
              dp[i][j] = dp[i-1][j]; 
        }
    }
    return dp[n][W];
}



int main() {
    // wt and val array should in be in sorted order
    // memset(dp,-1,sizeof(dp));
    vector<int> wt = {1,3,4,5};
    vector<int> val = {1,4,5,7};
    int W = 7;
    cout << maxProfit(wt,val,W,4);
}
