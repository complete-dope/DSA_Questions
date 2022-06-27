/*
What I can see is once whole array would be needed to traverse and other is we need to match it with the prev strings to combine them 
B.F. --> O(n2) , O(n)

*/


#include<iostream>
#include<bits/stdc++.h>
using namespace std;

string countSort(string s)
{
    int counter[26] = {0};
    for(auto i:s){
        counter[i-'a'] ++;
    }
    
    string t;
    for (int i = 0; i < 26; i++)
    {
        // https://stackoverflow.com/questions/11843226/multiplying-a-string-by-an-int-in-c
        // std::string(size_type count, char c);
        t += string(counter[i] , i+'a');
    }
    
    return t;

}

int main(){
    vector<string> vec = {"ate" , "eat" , "tae" , "bat" , "tab" ,"hui"};

    int n = vec.size();

    unordered_map<string , vector<string>> map;

    for(string s : vec){
        string t = s;
        sort(t.begin() , t.end());

        map[t].push_back(s);
    }

    vector<vector<string>> ans;

    for(auto i : map){
        ans.push_back(i.second);
    }
    
    // method one O(n2logn)

    // using countSort for complexity reduction 

    return 0;
}