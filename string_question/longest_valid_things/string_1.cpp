// longest palindromic substring

/* // expand around center we have 2 good ways to check the palindrome around a string and they are .. 1st one is checking the edges and going in (like i usually do) and second is starting from the center and going outwords (here we are going to see) */

// many subquestions can be made out of it 

// Q-1 Check if this string is a palindrome or not exist


#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    string s = "naman";
    int len =0;
    string str = "";
    int n = s.length();
    for (int i = 0; i < n; i++)
    {
        int left =i;
        int right = i;
            
        while(left>=0 && right < n && s[left] == s[right])
        {
            if(right-left+1 > len){
                len = right-left+1; 
                str = s.substr(left , (right-left)+1);
            }
            left--;
            right++;
        }
        // cout<<"enter2";
        left = i ;
        right = i+1;
        while(left>=0 && right <n && s[left] == s[right])
        {
            if(right-left+1 > len){
                len = right-left+1;
                str = s.substr(left , (right-left)+1);
            }
            left--;
            right++;
        }

    }
    cout<<str;

    return 0;
}