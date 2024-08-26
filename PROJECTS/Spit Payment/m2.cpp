#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<string> v;

    int n = 2;
    int tamount = 0;

    vector<vector<float>> exp;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter Total amount payed by " << v[i] << endl;
        int amtpayed;
        cin >> amtpayed;
        cout << endl;
        tamount += amtpayed;
        if (amtpayed == 0) // agar bill pay nahi kar raha hai
        {
            // agle pe chale jao
            continue;
        }

        else //apne alava kisi or ka bhi bill de sakta hai
        {

            for(int j=0;j<n;j++)
            {
                if(i!=j)
                {
                    cout<<j<<" ."<<v[j]<<endl;
                }
            }
            vector<pair<int, int>> temp;

            int x;
            while(1) //input lene ke liye
            {
                if(x==-1)
                break;
                cout<<"Enter Number associated for the person payed for"<<endl;
                cin>>x;

                if(x==-1)
                break;

                cout<<"Enter amount payed for that person "<<endl;
                int a;
                cin >> a;
                temp.push_back({x, a});
                amtpayed -= a;
            }

            for (auto it : temp)
            {
                exp[i][it.first] = it.second;
            }

        }
    }
}