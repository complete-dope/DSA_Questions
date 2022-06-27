// BS with transaction fees involved and infinite transaction allowed 

#include<iostream>
#include<bits/stdc++.h>
using namespace std;



int solve(vector<int> prices , int fee , bool bought ,int iter ,vector<vector<int>> &dp)
{
    if(iter >= prices.size()){
        return 0;
    }

    if(bought == false){
        if(dp[1][iter] != -1){
            return dp[1][iter];
        }

        return dp[1][iter] = max(solve(prices, fee ,!bought ,iter+1,dp) - prices[iter]-fee , solve(prices , fee, bought , iter+1,dp));
    }
    else{
        if(dp[0][iter] != -1){
            return dp[0][iter];
        }

        return dp[0][iter] =max(solve(prices, fee ,!bought ,iter+1,dp) + prices[iter] , solve(prices , fee, bought , iter+1,dp));
    }
}

 int maxProfit(vector<int>& prices, int fee) {
        int buy = -prices[0];
        int sell = 0; // same day buy and sell
        
        for(int i =1;i<prices.size();i++){
            buy = max(buy , sell-prices[i]);
            sell = max(sell , buy+prices[i]-fee);
        }
        
        return sell;
    }

int main(){
    //approach them greedily 
    vector<int> prices ={1,3,7,5,10,3};

    int n = prices.size();
    vector<vector<int>> dp(2,vector<int> (n,-1));
    int fee = 3;
    int ans =  solve(prices, fee , false  ,0 ,dp);
    cout<<dp[1][0];
    return 0;


   
}