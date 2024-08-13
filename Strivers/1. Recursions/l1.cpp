// stack overflow
// when function calls are waiting in memory and they are not completed then
// stack overflow or segmentation fault occurs duer to infinite recursions

// reverse array using recursion

#include <iostream>
#include <vector>

using namespace std;

// void reverse(vector<int>&arr,int s,int e)
// {
//     if(s>e)
//     return ;
//     swap(arr[s],arr[e]);
//     reverse(arr,s+1,e-1);
// }

// int main()
// {
//     vector<int>arr = {1};
//     reverse(arr,0,arr.size()-1);
//     for(auto it:arr)cout<<it<<" ";
// }

bool solve(string s ,int S,int E)
{
    if(S>=E)
    return true;

    if(s[S]==s[E])
        return solve(s,S+1,E-1);
    return false;
}
bool isPalindrome(string s)
{
    return solve(s,0,s.length()-1);
}

int main()
{
    cout<<isPalindrome("IN");
}