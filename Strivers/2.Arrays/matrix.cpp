#include <iostream>
#include <math.h>
#include <cstring>
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;

// set matrix 0
// TC O(N3)
// void convert_1(int row,int col,vector<vector<int>>&arr)
// {
//     for(int i=0;i<arr.size();i++)
//     {
//         if(arr[i][col]!=0)
//         arr[i][col] = -1;
//     }
//     for(int i=0;i<arr[0].size();i++)
//     {
//          if(arr[row][i]!=0)
//         arr[row][i] = -1;
//     }
// }
// int main()
// {
//     vector<vector<int>>arr = {{0,1,2,0},{3,4,5,2},{1,3,1,5}};
//     int n = arr.size();

//     for(int i=0;i<n;i++)
//     {
//         for(int j=0;j<arr[i].size();j++)
//         {
//             if(arr[i][j]==0)
//             {
//                 convert_1(i,j,arr);
//             }
//         }
//     }
//     for(int i=0;i<n;i++)
//     {
//         for(int j=0;j<arr[i].size();j++)
//         {
//             if(arr[i][j]==-1)
//             {
//                 arr[i][j] =0;
//             }
//         }
//     }
//     for(int i=0;i<n;i++)
//     {
//         for(int j=0;j<arr[i].size();j++)
//         {
//            cout<<arr[i][j]<<" ";
//         }
//         cout<<endl;
//     }
// }

// better solution
// // TC O(2*(N+M))
// int main()
// {
//     vector<vector<int>> arr = {{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}};
//     int n = arr.size();
//     int m = arr[0].size();
//     vector<int>col(m,0);
//     vector<int>row(n,0);
//     for(int i=0;i<n;i++)
//     {
//         for(int j=0;j<m;j++)
//         {
//             if(arr[i][j]==0)
//             {
//                 row[i] = 1;
//                 col[j] = 1;
//             }
//         }
//     }
//     for(int i=0;i<n;i++)
//     {
//         for(int j=0;j<m;j++)
//         {
//             if(row[i]==1 || col[j]==1)
//             arr[i][j]=0;
//         }
//     }
//     for(int i=0;i<n;i++)
//     {
//         for(int j=0;j<m;j++)
//         cout<<arr[i][j]<<" ";
//         cout<<endl;
//     }
// }

// optimal solution
// doubt
// // doubt
// int main()
// {
//     vector<vector<int>> arr = {{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}};
//     int n = arr.size();
//     int m = arr[0].size();

// }

// rotate matrix  by 90 degree
// brute force
// TC O(N2) SC O(N2)
// int main()
// {
//     vector<vector<int>> arr = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
//     int n = arr.size();
//     // i --> n-i-1
//     vector<vector<int>>ans(n,vector<int>(n,0));
//     for(int i=0;i<n;i++)
//     {
//         for(int j=0;j<n;j++)
//         {
//             ans[j][n-i-1] = arr[i][j];
//         }
//     }
//     for(int i=0;i<n;i++)
//     {
//         for(int j=0;j<n;j++)
//         {
//             cout<<ans[i][j]<<" ";
//         }
//         cout<<endl;
//     }
// }

// better
// int main()
// {
//     vector<vector<int>> arr = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
//     int n = arr.size();
//     // transpose the matrix

//    for (int i = 0; i < n; i++) {
//         for (int j = i + 1; j < n; j++) {
//             swap(arr[i][j], arr[j][i]);
//         }
//     }

//     for(int i=0;i<n;i++)
//     {
//     reverse(arr[i].begin(),arr[i].end());
//     }
//     for(int i=0;i<n;i++)
//     {
//         for(int j=0;j<n;j++)
//         cout<<arr[i][j]<<" ";
//         cout<<endl;
//     }
// }

// spiral
int main()
{
    vector<vector<int>> arr = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int n = arr.size();
    int m = arr[0].size();
    int top = 0, bottom = n - 1, left = 0, right = m - 1;
    vector<int> ans;
    while (left <= right && top <= bottom)
    {
        if (left <= right && top <= bottom)
        {
            for (int i = left; i <= right; i++)
            {
                ans.push_back(arr[top][i]);
            }
            top++;
        }
        if (left <= right && top <= bottom)
        {
            for (int i = top; i <= bottom; i++)
            {
                ans.push_back(arr[i][right]);
            }
            right--;
        }
        if (left <= right && top <= bottom)
        {
            for (int i = right; i >= left; i--)
            {
                ans.push_back(arr[bottom][i]);
            }
            bottom--;
        }
        if (left <= right && top <= bottom)
        {
            for (int i = bottom; i >= top; i--)
            {
                ans.push_back(arr[i][left]);
            }
            left++;
        }
    }
    
}