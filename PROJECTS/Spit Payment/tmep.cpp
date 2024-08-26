#include <iostream>
#include <bits/stdc++.h>
using namespace std;


int main()
{
    int n;
    cout << "Enter Number of persons" << endl;
    cin >> n;
    cout << endl;
    vector<string> v;

    int index = 0;
    while (n--)
    {
        cout << "Enter First Name of " << ++index << endl;
        string s;
        cin >> s;
        cout << endl;
        v.push_back(s);
    }
    n = index;



    vector<vector<float>> exp(n, vector<float>(n, 0));

    int tamount = 0;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter Total amount payed by " << v[i] << endl;
        int amtpayed;
        cin >> amtpayed;
        cout << endl;
        tamount += amtpayed;

        if (amtpayed == 0) // agar bill pay nahi kar raha hai
        {
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

            int x=0;
            int tempnum = n;
            tempnum--;
            while(tempnum--) //input lene ke liye
            {
                if(x==-1)
                break;
                cout<<"Enter Number associated for the person payed for"<<endl;
                cin>>x;

                if(x==-1)
                break;

                cout<<"Enter amount payed for that person "<<v[x]<<endl;
                int a;
                cin >> a;
                temp.push_back({x, a});
                amtpayed -= a;
            }
            temp.push_back({i, amtpayed});

            for (auto it : temp)
            {
                exp[i][it.first] = it.second;
            }

        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << exp[i][j] << " ";
        }
        cout << endl;
    }

    tamount /= n;

    // matrix ban gayi par ab calculate mon own kar raha hai or kon debt me hai

    // agar apna diya hoga to own 0 karega
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        int owe = tamount - exp[i][i];
        int get = 0;
        vector<int> toget;

        if (exp[i][i] >= tamount)
        {
            owe = 0;
            for (int j = 0; j < n; j++)
            {
                if (i != j && exp[i][j] != 0)
                {
                    get += exp[i][j];
                    toget.push_back(j);
                }
            }
        }

        int toown;
        for (int j = 0; j < n; j++)
        {
            if (exp[j][i] != 0)
            {
                toown = j;
                break;
            }
        }

        if (owe == 0 && get == 0)
        {
            cout << v[i] << " Has cleared bill " << endl;
        }
        else if (owe == 0 && get != 0)
        {
            cout << v[i] << " Does not owe any one and will get money from " << endl;
            for (auto it : toget)
            {
                cout << v[it] << " Amount " << tamount << endl;
            }
        }
        else
        {
            cout << v[i] << " Owes " << v[toown] << " Amount " << tamount-exp[i][i] << endl;
        }
        cout << endl;
        cout << endl;
    }
}