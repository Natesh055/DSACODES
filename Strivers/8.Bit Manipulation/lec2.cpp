#include<iostream>
#include<bits/stdc++.h>

using namespace std;

//check if ith bit is set or not
// int main()
// {
//     int n = 13;
//     int k = 4;
//     vector<int>ans;
//      while(n!=0)
//      {
//          ans.push_back(n%2);
//          n = n /2 ;
//      }
//      reverse(ans.begin(),ans.end());
//      return ans[ans.size()-k]==1;
// }





// set the ith bit
// int main()
// {
//     int n = 9;
//     int i = 2;
//     cout<<( n|(1<<i));
// }


// clear the ith bit

// int main()
// {
//     int n = 13;
//     int i = 2;
//     cout<< (n& ~(1<<i));
// }


// toggle the ith bit
// int main()
// {
//     int n = 13;
//     int k = 2;
//     cout<< (n ^ (1<<k));
// }




// remove the rightmost set bit
// int main()
// {
//     int n = 5;
//     cout<<(n&(n-1));
// }

// check if the number is power of 2
// int main()
// {
//     int n = 16;
//     cout<< ((n & (n - 1)) == 0);
// }

//count number of set bits 
int main()
{
    int n = 13;
    int count = 0;
    while(n!=0)
    {
        count+=n&1;
        n = n>>1;
    }

    cout<<count;
}