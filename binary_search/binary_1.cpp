#include<iostream>
#include<bits/stdc++.h>
using namespace std;


vector<int> searchRange(vector<int>& nums, int target) {
    //solve it using binary search algorithmn
    
    int start = 0;
    int end = nums.size()-1;
    vector<int> ans{-1,-1};
    //starting position 
    while(start<=end){
        int mid = start+(end-start)/2;
        
        if(target == nums[mid]){
            ans[0] = mid;
            end = mid-1;
        }
        else if(target < nums[mid]){
            end = mid-1;
        }
        else{
            start = mid+1;
        }
    }
    
    start = 0;
    end = nums.size()-1;
    while(start<=end){
        int mid = start+(end-start)/2;
        if(target == nums[mid]){
            ans[1] = mid;
            start = mid+1;
        }
        else if(target > nums[mid]){
            start = mid+1;
        }
        else if(target < nums[mid]){
            end = mid-1;
        }
    }
    return ans;
}

int main(){
    int n = 5;
    vector<int> arr{2,3,3,4};

    int target = 3;
    vector<int> ab;
    ab = searchRange(arr ,target);
    return 0;
}