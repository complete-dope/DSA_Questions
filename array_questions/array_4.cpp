// reverse the array with given k nodes

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> nums {1,2,3,4,5,6,7};
    int k = 3;
    int n = nums.size();
    int i =1;
    int s = 0;
    int e = s+k-1;
    int s1 = s;
    int e1 = e;
    while(i <= n/k){
        i++;
        while(s1 <= e1){
            swap(nums[s1] , nums[e1]);
            s1++;
            e1--;
        }
        s = s+k;
        e = s+k-1;
        s1 = s;
        e1 = e;
    }
    for (int i = 0; i < nums.size(); i++)
    {
        cout<<nums[i]<<" ";
    }
    

    return 0;
}