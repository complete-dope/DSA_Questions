/* 
Very very impt question --> 
*/
// Questions on this concept :

// Q-> no of times a sorted array is rotated
// Q-> find min in a rotated sorted array
// Q-> find least element
// Q-> search in a rotated sorted array 

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){

    vector<int> vec{4,5,6,1,2,3};
    int n = vec.size();
    int totalRotations = 0;

    int start =0;
    int end = n-1;

    while(start<=end){
        if (vec[start]<=vec[end])
        {
            cout<<vec[start];
            break;
        }
        int mid = start + (end-start)/2;
        int next = (mid+1)%n;
        int prev = (mid+n-1)%n;
        if(vec[mid] <= vec[prev] && vec[mid] <= vec[next])
        {
            cout<<vec[mid];
            break;
        }
        else if(vec[mid] >= vec[start])
        {
            start = mid+1;
        }
        else if(vec[mid] <= vec[end]){
            end = mid-1;
        }
    }
    return 0;
}

