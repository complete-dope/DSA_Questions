/*
LC-1319 
No of operations to make network connected

*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<vector<int>> arr {{0,1} , {0,2} , {0,3} ,{1,2} ,{1,3}};
    int n = 6;

    if(arr.size()+1 < n)
    {
        cout<<"we got "<<endl;
        return 1;
    }

    //bfs traversal
    unordered_map<int ,list<int>> adjList;
    for(int i = 0 ; i<arr.size();i++)
    {
        adjList[arr[i][0]].push_back(arr[i][1]);
        adjList[arr[i][1]].push_back(arr[i][0]);
    }
    //adj created 
    // calculate useless nodes 
    //dfs
    vector<bool> visited(n ,false);
    vector<int> parent(n , -1);

    for(int i = 0 ; i<n;i++)
    {
        solve(adjList ,visited , parent , i);
    }

    return 0;
}

void solve(unordered_map<int,list<int>> &adjList, vector<bool> visited , vector<int> parent , int i)
{

}