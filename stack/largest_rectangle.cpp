#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int largestRectangleArea(vector<int>& heights) {
        // I need to find the nearest smallest to the left 
        // and nearest smallest to the right 
        
        
        // left smallest here I would use indexing only
        stack<pair<int ,int>> s1;
        stack<pair<int ,int>> s2;
        int n = heights.size();
        vector<int> v1(n);
        
        //left to right (left smallest) 
        s1.push(make_pair(heights[0]  , 1));
        int i = 1;
        while(!s1.empty() && i<n)
        {
            pair<int , int> p;
            p = s1.top();
            if(p.first < heights[i])
            {
                v1[i] = p.second;
                
                s1.push(make_pair(heights[i] , i+1));
                i++;
            }
            else{
                s1.pop();
            }
            if(s1.empty())
            {
                s1.push(make_pair(heights[i] , i+1));
                v1[i] = 0;
                i++;
            }
        }
        
//         for(auto i  :v1)
            
//         {
//             cout<<i<<" ";
//         }
        
        //right to left (right smallest)
        s2.push(make_pair(heights[n-1] , n));
        i = n-2;
        vector<int> v2(n);
        v2[n-1] = n+1;
        while(!s2.empty() && i>=0)
        {
            pair<int , int> p;
            p = s2.top();
            if(p.first < heights[i])
            {
                v2[i] = p.second;
                
                s2.push(make_pair(heights[i] , i+1));
                i--;
            }
            else{
                s2.pop();
            }
            if(s2.empty())
            {
                s2.push(make_pair(heights[i] , i+1));
                v2[i] = n+1;
                i--;
            }
        }
        
//         cout<<"second arra"<<endl;
//         for(auto i : v2)
//         {
//             cout<<i<<" ";
//         }
        
        // made both arrays
        
        vector<int> diff(n);
        // cout<<" valeus"<<endl;
        // cout<<v1[0] << v2[0]<<endl;
        // cout<<"diff"<<endl;
        for(int i = 0; i<n;i++)
        {
            int a = 0;
            if(v1[i]>v2[i])
            {
                a = v1[i]-v2[i];
            }else{
                a = v2[i]-v1[i];
            }
            diff[i] = (a-1 )*heights[i];
            
        }
        return *max_element(diff.begin() , diff.end());
    }

int main(){
    vector<int> heights{1,4,3,5,0,6};
    return largestRectangleArea(heights);
}