//
// Created by Dipayan Bhattacharya on 3/5/17.
//
#include <vector>
#include <iostream>

using namespace std;
/*
 * You are given coins of different denominations and a total amount of money amount. Write a function to compute the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

Example 1:
coins = [1, 2, 5], amount = 11
return 3 (11 = 5 + 5 + 1)

Example 2:
coins = [2], amount = 3
return -1.

Note:
You may assume that you have an infinite number of each kind of coin.
 */
int coinChange(vector<int>& coins, int amount) {
    int dp[amount+1];
    memset(dp,-1,(amount+1)*sizeof(int));
    dp[0] = 0;
    for(int i=1;i<=amount;i++) {
        for(int j=0;j<coins.size();j++) {
            if(i>=coins[j] && dp[i-coins[j]] > -1) {
                if(dp[i] == -1) {
                    dp[i] = dp[i - coins[j]] + 1;
                } else {
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
                }
            }
        }
    }
    return dp[amount];
}

/*
 * You are given coins of different denominations and a total amount of money. Write a function to compute the number of combinations that make up that amount. You may assume that you have infinite number of each kind of coin.

Note: You can assume that

0 <= amount <= 5000
1 <= coin <= 5000
the number of coins is less than 500
the answer is guaranteed to fit into signed 32-bit integer
Example 1:

Input: amount = 5, coins = [1, 2, 5]
Output: 4
Explanation: there are four ways to make up the amount:
5=5
5=2+2+1
5=2+1+1+1
5=1+1+1+1+1
 */
int coinChange2(int amount, vector<int>& coins) {
    int dp[amount+1];
    memset(dp, 0, (amount+1)*sizeof(int));
    dp[0] = 1;
    for(int i=0;i<coins.size();i++) {
        for(int j=coins[i];j<=amount;j++) {
            dp[j] = dp[j] + dp[j-coins[i]];
        }
    }
    return dp[amount];
}
int main(int argc, char **argv) {
    vector<int> coins1 = {1, 2, 5};
    int amount1 = 11;

    cout<<"Result = "<<coinChange(coins1, amount1)<<endl;

    vector<int> coins2 = {1, 2, 5};
    int amount2 = 5;
    cout<<"Result = "<<coinChange2(amount2, coins2)<<endl;
}
