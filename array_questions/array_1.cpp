#include<iostream>
#include<bits/stdc++.h>
using namespace std;


int main(){
    int array[6] = {4,2,0,3,2,5};
    int n = sizeof(array)/sizeof(1);

    int left[n];
    left[0] = array[0];
    int right[n];
    right[n-1] =array[n-1];

    int enditer = n;
    for (int i = 1; i < n; i++)
    {
        left[i] = max(left[i-1] , array[i]);
        cout<<left[i]<<" ";
         
    }
    cout<<endl;
    for (int i = n-2; i >= 0; i--)
    {
        right[i] = max(right[i+1] , array[i]);
        cout<<right[i]<<" "; 
    }
    cout<<endl;
    //made it
    int ans =0;
    for (int i = 0; i < n; i++)
    {
        // cout<<right[i]<<"";
        ans += min(left[i] , right[i]) - array[i];
    }
    cout<<ans;
    return 0;
}