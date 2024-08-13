#include <iostream>
#include <math.h>
#include <cstring>
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;

// Kth Missing Positive Number
int main()
{
    vector<int>arr = {2,3,4,7,11};
    int k = 5;
    
    int s = 0;
    int e = arr.size()-1;

    while(s<=e)
    {
        int mid = (s+e)/2;
        int miss = arr[mid] - (mid+1);

        if(miss <k)
        {
            s = mid+1;
        }
        else
        {
            e = mid-1;
        }
    }
    cout<<e+1+k;
}