// House robbery m bs first and last are connected 

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int solve(int arr[] ,int start , int end)
{
    if(start > end)
    {
        return 0;
    }

    int a = solve(arr , start+2 , end) + arr[start];
    int b = solve(arr , start+1 , end);
    return max(a,b);
}


int main(){
    int arr[] = {1,2,3};
    // max house robbery with adj house on both sides can't rob
    int n = sizeof(arr)/sizeof(4);
    int case1 = solve(arr, 0 , n-2);
    int case2 = solve(arr ,1 , n-1);
    cout<<max(case1 , case2);


    return 0;
}