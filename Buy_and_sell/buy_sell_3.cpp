// infinitely buy and sell stcoks with max profit allowed --> BSBSBSBS

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    int arr[8] = {1,4,2,3,1,5,6,7};
    int n = sizeof(arr)/sizeof(10);
    int min = arr[0];
    int ans =0;

    
    for (int i = 0; i < n; i++)
    {
        if(arr[i] < arr[i-1]){
            ans += arr[i-1] - min;
            min = arr[i];
        }
    }
    if(min != arr[n-1]){
        ans += arr[n-1] - min;
        min = arr[n-1];
    }

    cout<<ans;
    
    
    // also update every single pass no matter the value it is 
    for (int i = 0; i < n; i++)
    {
        if(arr[i] < arr[i-1]){
            min = arr[i];
        }
        else{
            ans += arr[i]-min;
            min = arr[i];
        }
    }
    cout<<ans;
    
    return 0;
}


