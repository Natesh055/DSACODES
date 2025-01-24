#include<iostream>
#include<bits/stdc++.h>
using namespace std;
// job sequencing problem

int main()
{
    vector<int> deadline = {2,6,6,5,4,2,4,2};
    vector<int>profit = {80,70,65,60,25,22,20,10};
    int n = deadline.size();


    int count =0,prcount = 0;
    int maxi = 0;
    for(int i=0;i<n;i++)
    {
        maxi = max(maxi , deadline[i]);
    }
    vector<int>total(maxi,-1);

    //as the profits are in sorted order
    for(int i=0;i<n;i++)
    {
        if(total[deadline[i]]!=-1){
            total[deadline[i]] = 1;
            prcount++;
            count++;

            }
        else{
            for(int j =i-1;j<=0;j--)
            {
                if(total[deadline[j]]!=-1)
                {
                    total[deadline[j]] = 1;
                    break;
                    prcount++;
                    count++;
                }
            }
        }
cout<<count;
    }

}