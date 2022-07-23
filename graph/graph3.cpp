// rat in a maze (backtracking / dfs traversal)
/*
rat needs to go from 0 ,0 to N-1,N-1 in all directions the rat can go
but the rat can only travel to values of 1
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void solve(vector<vector<int>> matrix , int N , int sx ,int sy ,
int ex ,int ey ,string s, vector<string> &ans)
{
    if(sx == ex && sy == ey)
    {
        ans.push_back(s);
    }
    // base case
    if(sx <0 || sx>N || sy<0 || sy>N)
    {
        return;
    }
    matrix[sx][sy] = 0;
    //lets go right 00 --> 01 && value should be 1
    if( sy+1<N && matrix[sx][sy+1] == 1)
    {
        solve(matrix , N , sx , sy+1 , ex , ey , s+'R' ,ans);
    }

    //lets go left 00 --> 0,-1 value should be 1
    if(sy-1>=0 && matrix[sx][sy-1] == 1)
    {
        solve(matrix , N , sx , sy-1 , ex , ey , s+'L' ,ans);
    }

    //lets go up 00 --> -1,0 value should be 1
    if(sx-1 >= 0 && matrix[sx-1][sy] == 1)
    {
        solve(matrix , N , sx-1 , sy , ex , ey , s+'U' ,ans);
    }

    //lets go down 00 --> 10 value should be 1
    if(sx+1<N && matrix[sx+1][sy] == 1)
    {
        solve(matrix , N , sx+1 , sy , ex , ey , s+'D' ,ans);
    }

    return;
}

int main(){
    // vector<vector<int>> matrix{{1, 0, 0, 0},
    //                     {1, 1, 0, 1}, 
    //                     {1, 1, 0, 0},
    //                     {0, 1, 1, 1}};
    vector<vector<int>> matrix{{1,0},{1,0}};
    int N = 2;
    vector<string> ans;
    // if(matrix[0][0] == 0) return ans;
    solve(matrix , N ,0 , 0 , N-1 ,N-1 , "" , ans);    
    if(ans.empty())
    {
        cout<<-1<<endl;
    }
    for(auto i : ans){
        cout<<i<<" ";
    }               
    return 0;
}