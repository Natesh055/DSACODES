#include <iostream>
#include <math.h>
#include <cstring>
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;
// finding square root of a number using binary search

int main()
{
    long long int x = 4;
    long long int s = 1;
    long long int e = x;
    long long int ans = 0;

    while(s<=e)
    {
        long long int mid = (s+e)/2;
        if(mid * mid <=x)
        {
            ans = mid;
            s = mid+1;
        }
        else
        e = mid-1;

    }
    cout<<ans;
}