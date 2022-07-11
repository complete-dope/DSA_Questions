// bubble sort --> 2/7/22

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    int arr[12] = {10 ,1 , 7 ,6 ,14 ,9 ,-1 ,21 ,5 ,23, 14 ,41};

    int n = sizeof(arr)/sizeof(12);
    for (int i = 0; i < n-1; i++)
    {
        bool swapped = false;
        for (int j = 0; j < n-i-1; j++)
        {
            if(arr[j] > arr[j+1]){
                swap(arr[j] , arr[j+1]);
                swapped = true;
            }
        }
        if(swapped == false){
            break;
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    
    
    return 0;
}