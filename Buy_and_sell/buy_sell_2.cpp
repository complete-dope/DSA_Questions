// buy and sell stock same as last one but here we can do that twice BSBS allowed not BBSS .

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    int array[6] = {4,1,8,3,9,2};
    int n = sizeof(array)/sizeof(100); // 8*4/4


    // same from left to right as last question 
    int minVal = array[0];
    int dpltr[n];
    dpltr[0] =0;
    int dprtl[n];
    dprtl[n-1]=0;

    for (int i = 1; i < n; i++)
    {
        minVal = min(minVal , array[i]);
        dpltr[i] = max(dpltr[i-1] , array[i]-minVal);
    }

    int sum =dpltr[n-1] + dprtl[n-1]; //final ans
    int maxVal = array[n-1];
    for (int i = n-2; i >= 0; i--)
    {
        maxVal = max(maxVal , array[i]);
        dprtl[i] = max(dprtl[n-1] , maxVal-array[i]);
        sum = max(sum , dpltr[i]+ dprtl[i]);
    }
    
    cout<<sum;


    return 0;
}