/*
Longest increasing subsequence and russian dolls 
dp with binary search --> 
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int lis(string s, string f , int s1 , int s2 )
{
    //base case
    if(s1<=0 || s2<=0)
    {
        return 0;
    }

    if(s[s1-1] == f[s2-1])
    {
        return 1+lis(s , f , s1-1 , s2-1);
    }
    else{
        return max(lis(s , f , s1, s2-1)  ,
        lis(s , f ,s1-1 , s2));
    }
}


//the longest common subsequence way 

int liss(int s[] , int f[] , int s1 , int s2)
{
    if(s1<=0 || s2<=0)
    {
        return 0;
    }

    if(s[s1-1] == f[s2-1])
    {
        return 1+liss(s , f , s1-1 , s2-1);
    }
    else{
        return max(liss(s , f , s1, s2-1)  ,
        liss(s , f ,s1-1 , s2));
    }
}

//start --> -inf
int lisss(int arr[] , int n , int i , int start)
{
    if(i >= n)
    {
        return 0;
    }
    if(arr[i] > start)
    {
        return max(lisss(arr, n , i+1 , arr[i]) + 1 , lisss(arr , n , i+1 , start));
    }else{
        return lisss(arr , n ,i+1 , start);
    }

}

int lower_boundd(vector<int> &ans , int val)
{
    if(val < ans[0])
    {
        return 0;
    }
    int n = ans.size();
    int start = 0;
    int end = n; // not n-1;
    while(start<end)
    {
        int mid = (start+end)/2;
        if(val <= ans[mid])
        {
            end = mid;
        }
        else{
            start = mid+1;
        }
    }
    return start;
}

int dpWithBS(int arr[] , int n)
{
    if(n==0)
    {
        return 0;
    }

    vector<int> ans;
    ans.push_back(arr[0]);

    for (int i = 1; i < n; i++)
    {
        if(arr[i] > ans.back())
        {
            ans.push_back(arr[i]);
        }

        // int index = lower_bound(ans.begin() , ans.end() , arr[i]) - ans.begin();
        int index  = lower_boundd(ans , arr[i]);
        ans[index] = arr[i];
    }
    return ans.size();
} 

int main(){
    string s = "abd";
    string f = "dab";
    int n = s.length();
    cout<<lis(s , f ,n,n)<<endl;

    int arr[5] = {1,2,3,4,5};
    int arr2[5] = {3,1,2,5,4};
    cout<<liss(arr , arr2  , 5 ,5)<<endl;

    int arr3[] = {1,4,21,23,11,9,1232,12};
    int n3 = sizeof(arr3)/sizeof(4);
    cout<<lisss(arr3, n3 , 0 , INT_MIN)<<endl;;

    // memoization of code ho jaega
    // tabulation of code
    // DP with binary search 
    cout<<dpWithBS(arr3 , n3);
    return 0;
}

