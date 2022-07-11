// Selection sort in a array --> 2/7/22
/*
One of the favourite topic of interview mcqs 
Must Read ->
 https://stackoverflow.com/questions/1517793/what-is-stability-in-sorting-algorithms-and-why-is-it-important
*/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    int arr[11] ={64,35,89,11,22 , -1 , -231241 ,2532 , 25  , 423 , 4521};
    int n = sizeof(arr)/sizeof(23);
    int mini ;
    int index = -1;
    for (int i = 0; i < n-1; i++)
    {
        mini = arr[i];
        index = i;
        for (int j = i+1; j < n; j++)
        {
            if(mini > arr[j]){
                index = j;
                mini = arr[j];
                cout<<mini<< " ";
            }
        }
        cout<<endl;
        swap(arr[i] , arr[index]); // swap ho ja
    }
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}