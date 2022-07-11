// Merge sort --> very important --> 3/7/22


#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void merge(int *arr , int s , int e){
    int mid = (s+e)/2;
    int len1 = mid-s +1;
    int len2 = e-mid;

    int *arr1 = new int[len1]; // heap memory allocation of a stack is done here
    int *arr2 = new int[len2];

    //copy the values into the new array
    int startingVal = s;
    for (int i = 0; i < len1; i++)
    {
        arr1[i] = arr[startingVal++];
    }
    startingVal = mid+1;
    for (int i =0; i < len2; i++)
    {
        arr2[i] = arr[startingVal++];
    }
    //merge 2 sorted arrays

    int index1 =0;
    int index2 = 0;
    startingVal = s;

    while(index1 < len1 && index2 < len2)
    {
        if(arr1[index1] < arr2[index2])
        {
            arr[startingVal++] = arr1[index1++];
        }
        else
        {
            arr[startingVal++] = arr2[index2++];
        }
    } 

    while(index1 < len1)
    {
        arr[startingVal++] = arr1[index1++];
    }
    while(index2 < len2)
    {
        arr[startingVal++] = arr2[index2++];
    }
}

void mergeSort(int *arr , int s , int e)
{
    if(s >=e ){
        return;
    }

    int mid = (s+e)/2;
    mergeSort(arr , s , mid);
    mergeSort(arr , mid+1 , e);
    merge(arr , s ,e);
}


int main(){
    int arr[10]  = {4,2,1,3,5, 42,3121, -12 , -31, 42};
    int n = sizeof(arr)/sizeof(4);

    mergeSort(arr , 0 , n-1);
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }cout<<endl;
    
    
    return 0;
}