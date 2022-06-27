// do infinite transaction but here with a cooldaown values  LC -> buy and sell ii 
// BSCBS

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> dp(2, vector<int>(5000, -1));
// ...... 0 1 2 3 4 5 6 ..x5000
// True
// False

int solve(vector<int> &prices ,int iter , bool bought){
    //bc
    if(iter >= prices.size()){
        return 0;
    }

    if(bought == false){
        if(dp[1][iter] != -1){
            return dp[1][iter];
        }
        int a = solve(prices , iter+1 ,!bought);
        int b = solve(prices ,iter+1 ,bought);

        dp[1][iter] =  max(a-prices[iter],b);
        return max(a-prices[iter],b);
    }
    else{
        if(dp[0][iter] != -1){
            return dp[0][iter];
        }


        int a = solve(prices , iter+2 ,!bought);
        int b = solve(prices ,iter+1 ,bought);
        dp[0][iter] =  max(a + prices[iter] ,b);
        return max(a + prices[iter] ,b);
    }
}


int main(){
    vector<int> prices = {1,2,3,0,2};
    int n = prices.size();
    bool bought = false;
    int ans = solve(prices , 0 , bought);
    cout<<dp[1][0];

    cout<<endl;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            cout<<dp[i][j]<<" ";
        }cout<<endl;
        
    }
    
    return 0;
}