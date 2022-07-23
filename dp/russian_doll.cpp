/*
LC --> 354

Russian doll (hard)
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool myfunc(vector<int> &a , vector<int> &b)
{
    if(a[0] == b[0])
    {
        return a[1]>b[1];
    }
    else{
        return a<b;
    }
}


int solveBS(vector<int> heights , int n)
{
    vector<int> ans;
    if(n==0)
    {
        return 0;
    }

    ans.push_back(heights[0]);
    cout<<"bf for loop"<<endl;
    for (int i = 1; i < n; i++)
    {
        if(heights[i] > ans.back())
        {
            ans.push_back(heights[i]);
        }
        cout<<"ins for"<<endl;
        int index= lower_bound(ans.begin() ,ans.end() , heights[i]) - ans.begin();
        ans[index] = heights[i];
    }
    return ans.size();
}

int main(){
    vector<vector<int>> arr {{5,4} , {6,4} , {6,7} , {2,3}};
    int n = arr.size();
    cout<<"bf sort"<<endl;
    // width and height
    //increasing order of width but is width ties sort in descending order of height
    cout<<n<<endl;
    sort(arr.begin() , arr.end() , myfunc);
    vector<int> heights;
    cout<<"sorted"<<endl;
    for(auto i: arr)
    {
        cout<<i[1]<<" ";
        heights.push_back(i[1]);
    }
    // for(auto i : heights)
    // {
    //     cout<<i<<" ";
    // }cout<<endl;
    cout<<"heights is "<<heights.size()<<endl;
    cout<<"calling func"<<endl;
    cout<<solveBS(heights , n);
    return 0;

}
