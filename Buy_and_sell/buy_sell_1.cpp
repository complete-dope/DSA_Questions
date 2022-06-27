// max profit that can be made from a particular sale of a stock (only once allowed)


#include<bits/stdc++.h>

using namespace std;

int main(){
    int array[8] = {5,26,2,6,34,32,2,7};
    int n = sizeof(array)/sizeof(100); // 8*4/4
    int minVal = array[0];
    int ans = 0;

    for (int i = 1; i < n; i++)
    {
        minVal = min(minVal , array[i]);
        ans = max(ans , array[i]-minVal);
    }
    cout<<ans;

    return 0;
}
