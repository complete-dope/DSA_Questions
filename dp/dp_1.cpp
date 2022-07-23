/* 
Count all subsequences having product less than K gfg
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int solve(int *arr , int k , int i , int n)
{
    if(i<0)
    {
        return 0;
    }

    if(k/arr[i] > 0)
    {
        int a = 1+solve(arr , k/arr[i] , i-1 ,n);
        int b = solve(arr , k ,i-1 ,n);
        return a+b;
    }
    else{
        return solve(arr ,k ,i-1,n);
    }
}


int main(){
    int arr[4] = {4, 8, 7, 2};
    int n = sizeof(arr)/sizeof(9);
    int k = 50;
    int i = n-1;
    cout<<solve(arr , k , i , n);
    return 0;

}