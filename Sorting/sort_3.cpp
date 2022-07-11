// insertion sort --> 2/7/22


#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    int arr[6] = {4,2,8,19,10,1};

    int n = sizeof(arr)/sizeof(2);
    for (int i = 1; i < n; i++)
    {
        int temp = arr[i];
        int j = i-1;
        for (; j >=0; j--)
        {   
            if(arr[j] > temp){
                //shift
                arr[j+1] = arr[j];

            }
            else{
                break;
            }
        }
        arr[j+1] = temp;
        
    }
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    

    return 0;
}