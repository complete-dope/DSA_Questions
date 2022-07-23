/*
Stack has very limited questions and the questions stack have are very trivial and important must done questions are their.
*/

// Stack identification is when the inside loop is dependent on the outer loop such as i is dependent on j 

// Nearest Smallest number on left and right 

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    int arr[6] = {1,8,9,0,8,10};
    int n = sizeof(arr)/sizeof(12);

    // brute force
    
    vector<int> v(n);
    /*
    v[0] = -1;
    int mini = arr[0];
    for (int i = 1; i < n; i++)
    {
        mini =arr[i];
        for(int j = i-1 ; j>=0 ; j--){
            if(arr[j] < arr[i])
            {
                v[i] = arr[j];
                break;
            }
            else{
                continue;
            }
        }
    }
    for(auto i : v)
    {
        cout<<i<<" ";
    }
    */

    // an optimised technique 
    // as here we can see j is dependent on loop i so we do use a stack here

    stack<int> st;
    st.push(arr[0]);
    v[0] = -1;
    int i =1;
    while(!st.empty() && i < n)
    {
        if(st.top() < arr[i])
        {
            v[i] = st.top();
            st.push(arr[i]);
            i++;
        }
        else{
            st.pop();
        }
        if(st.empty())
        {
            st.push(arr[i]);
            v[i] = -1;
            i++;
        }

    }
    for(auto i : v)
    {
        cout<<i<<" ";
    }
    return 0;
}