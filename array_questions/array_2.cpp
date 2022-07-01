// product of array except self

/*
Q--> 
Input: nums = [1,2,3,4]
Output: [24,12,8,6]

Approach1 = first calculate the whole value of the array by multiplying each value with each other and then divide as you move forward in it . 

Approach2 = maintain 2 arrays and in one maintain multiply from start and in other from end and for ans multiply i with n-i-1 values 
// LC - 238
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> v {1,2,3,4};

    int n = v.size();
    vector<int> forwVal(n);
    vector<int> backwVal(n);
    forwVal[0] = 1;
    backwVal[0] = 1; 
    vector<int> resArr(n);
    for (int i = 1; i < n; i++)
    {
        forwVal[i] = forwVal[i-1] * v[i-1];
        backwVal[i] = backwVal[i-1] * v[n-i];
    }

    for (int i = 0; i < n; i++)
    {
        resArr[i] = forwVal[i]*backwVal[n-1-i];
        cout<<resArr[i]<<" ";
    }

    return 0;
}

