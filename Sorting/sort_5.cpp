// Quick Sort --> 3/7/22
/*

One of the most important sorting algo and very high chance of coming up in interviews
*/


#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int partition(int *arr , int s , int e)
{
    int start = arr[s];
    int cnt = 0;
    
    for (int i = s+1; i <= e; i++)
    {
        if(start > arr[i]){
            cnt++;

        }
    }

    int pivotIndex = s + cnt;

    swap(arr[pivotIndex] , arr[s]);

    int i  = s;
    int j = e;
    while(i<pivotIndex && j > pivotIndex){
        while(arr[i] <= arr[pivotIndex]){
            i++;
        }
        while (arr[j] > arr[pivotIndex] )
        {
            j--;
        }
        if(i<pivotIndex && j>pivotIndex){
            swap(arr[i++] , arr[j--]);
        }
    }
    return pivotIndex;
    
}

void quickSort(int* arr , int s , int e)
{
    if(s >= e){
        return;
    }

    int p = partition(arr , s ,e);
    quickSort(arr , s ,p-1);
    quickSort(arr , p+1 , e);
}



int main(){
    int arr[11] = {3,1,4,5,2, 4 ,342 , 52, 42, 52, 5};
    int n = sizeof(arr)/sizeof(32);

    int s =0;
    int e = n-1;

    quickSort(arr , s ,e);
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    

    return 0;
}