#include<iostream>
#include<bits/stdc++.h>

using namespace std;


int main()
{
    int n = 4;
    // now calculating number of bits in n
    long count = 0;
    while(n>0)
    {
        n/=2;
        count++;
    }


    long maxi = 0;
    long num = 0;
    long result = 0;
    for(int i = n;i<pow(2,count);i++)
    {
        num=num^i;
        if(num>maxi)
        {
            result = i;
            maxi = num;
        }
    }
    cout<<result;
}
