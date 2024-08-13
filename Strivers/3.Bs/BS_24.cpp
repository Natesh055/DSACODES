#include <iostream>
#include <math.h>
#include <cstring>
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;

int main()
{
    vector<vector<int>> arr = {{-10, -10, -8, -7, -6},
                                {-4, -4, -3, -2, 0},
                                {1, 1, 2, 2, 4}};
    int k = -4;w
    int m = arr.size();
    int n = arr[0].size();
    int s = 0;
    int e = n - 1;

     // for finding the row

     int row=0;
        for(int i=0;i<m;i++)
        {
            if(arr[i][s]<=k && k<=arr[i][e])
            {
                row = i;
                break;
            }
        }

        while(s<=e) 
        {
            // element in the same row
            int mid = (s+e)/2;
            if(arr[row][mid]==k)
            {
                cout<<mid;
                cout<<1;
                break;
            }

            else if(arr[row][mid]>k)
            e = mid-1;
            else 
            s = mid+1;
        }

}