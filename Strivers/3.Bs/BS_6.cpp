#include <iostream>
#include <math.h>
#include <cstring>
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;
// pickup the smallest element and eliminate its search space
int main()
{
    vector<int> arr = {2,1};
    int mini = INT_MAX;
    int s = 0, e = arr.size() - 1;
   while (s <= e)
    {
        int mid = (s + e) / 2;
        // if alreday sorted
        if(arr[s]<= arr[e])
        {
            mini = min(mini,arr[s]);
            break;
        }
        // if left half is sorted
        if (arr[s] <= arr[mid])
        {
                mini = min(arr[s],mini);
                s = mid + 1;
        }
        // right half is sorted
        else
        {
                mini = min(arr[mid],mini);
                e = mid - 1;
        }
    }
    cout<<mini;
}