#include<iostream>
#include<bits/stdc++.h>
using namespace std;


//lemonade change
int main()
{
    vector<int>arr = {5,5,5,10,20};
    int n = arr.size();
    int c5=0,c10=0;
    sort(arr.begin(),arr.end());
    for(int i=0;i<n;i++){
        if(arr[i]==5)c5++;
         if(arr[i]==10){
            if(c5>1){
                c5--;c10++;
            }
            else return false;
         }
         else{
            if(c10>0 && c5>0){
                c10--;
                c5--;
            }
            else if(c5>2){
                c5=c5-3;
            }
            else return false; 
         }
    }
    return true;
    
}