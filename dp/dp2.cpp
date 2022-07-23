/*
Egg dropping problem --> mcm pattern
min no of floors to be used so we get min in the worst case 
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int static dp[101][10001];
int solve(int eggs , int floors)
{
    if(eggs == 1 || floors == 1 || floors == 0)
    {
        return floors;
    }

    int mn = INT_MAX;
    for (int k = 1; k <= floors; k++)
    {
        int temp = 1+ max(solve(eggs-1 , k-1) , solve(eggs , floors-k));
        mn = min(mn ,temp);
    }
    return mn;
    
}

int solveMem(int eggs , int floors)
{
    if(eggs == 1 || floors == 1 || floors == 0)
    {
        return floors;
    }

    if(dp[eggs][floors] != -1)
    {
        return dp[eggs][floors];
    }

    int mn = INT_MAX;
    for (int k = 1; k <= floors; k++)
    {
        int temp = 1+ max(solveMem(eggs-1 , k-1) , solveMem(eggs , floors-k));
        mn = min(mn ,temp);
    }
    dp[eggs][floors] = mn;
    return mn;
}


int solveMem2(int eggs , int floors)
{
    if(eggs == 1 || floors == 1 || floors == 0)
    {
        return floors;
    }

    if(dp[eggs][floors] != -1)
    {
        return dp[eggs][floors];
    }

    int mn = INT_MAX;
    for (int k = 1; k <= floors; k++)
    {
        int low;
        int high;
        if(dp[eggs-1][k-1] != -1)
        {
            low = dp[eggs-1][k-1];
        }
        else{
            low = solveMem2(eggs-1 , k-1);
            dp[eggs-1][k-1] = low;
        }

        if (dp[eggs][floors-k] != -1)
        {
            high = dp[eggs][floors-k];
        }
        else
        {
            high = solveMem2(eggs , floors-k);
            dp[eggs][floors-k] = high;
        }
        
        int temp = 1+ max(low , high);
        mn = min(mn ,temp);
    }
    dp[eggs][floors] = mn;
    return mn;
}

int solveBin(int eggs , int floors)
{
    if(eggs == 1 || floors == 1 || floors == 0)
    {
        return floors;
    }

    int ans=INT32_MAX;
    int l=1,r=floors;
    while(l<=r)
    {
        int mid=(l+r)/2;
        int left = solveBin(eggs-1,mid-1);
        int right = solveBin(eggs,floors-mid);
        int temp = 1 + max(left,right);
        if(left<right)
        {
            l=mid+1;
        }
        else
        {
            r=mid-1;
        }
        ans = min(ans,temp);
    }
    dp[eggs][floors]=ans;
    return ans;
}


int main(){
    int f = 6;
    int e = 2;

    //total floors 7 and eggs are 3 
    memset(dp , -1 , sizeof(dp));
    // cout<<solve(e,f);
    // cout<<solveMem2(e , f);
    cout<<solveBin(e ,f);
    return 0;
}