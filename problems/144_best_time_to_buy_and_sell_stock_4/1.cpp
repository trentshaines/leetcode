
#include <vector>
using namespace std;
class Solution {
public:
  int solve(int i, int k, vector<vector<int>>& dp, vector<int>& prices){
    //  base case
    // Need more than 1 to make a profit.
    if (i == 0 || k < 0)
        return 0;

    if (dp[i][k] != -1)
        return dp[i][k];

    // Consider not using the trade
    dp[i][k] = solve(i-1, k, dp, prices);

    // Go right to left and find the optimal splitting point.
    // edit: just realized there's no need to do this running sum thing. We can just test each buy and sell range....
    int cur_gain = 0;
    int max_gain = 0;
    for(int split = i-1; split >= 0; --split){
        cur_gain = max(0, cur_gain + prices[split+1] - prices[split]);
        max_gain = max(max_gain, cur_gain);
        
        dp[i][k] = max(max_gain + solve(split, k-1, dp, prices), dp[i][k]);
    }

    return dp[i][k];
  }

  int maxProfit(int k, vector<int> &prices) {
    // dp[i][k], where i is index, k is remaining transactions.
    // kadane like approahc from right to left to find current segment max profit

    int n = prices.size();
    vector<vector<int>> dp(n, vector<int>(k, -1));

    return solve(n-1, k-1, dp, prices);
  }
};