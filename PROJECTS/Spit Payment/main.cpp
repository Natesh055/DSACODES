#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void payedfor(vector<vector<float>> p, int i)
{
    for (int i = 0; i < p.size(); i++)
    {
    }
}
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

    // abhi ek ka bana raha hu
    vector<pair<string, vector<vector<float>>>> ttt;

    // ab kisne kiske liye pay kiya
    // sanidhya->natesh,Shivansh piyush ne apna

    int sum = 0;
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

        else
        {

            cout << v[i] << " Payed for" << endl;
            vector<int> temp;
            temp.push_back(i);
            for (int j = 0; j < n; j++)
            {
                int x;
                // apna bill to dega hi aadmi
                if (x != -1) // agar bill nahi diya
                {
                    if (i != j)
                    {
                        cout << v[j] << " " << j << " Enter number associated" << endl;
                        int x;
                        cin >> x;
                        cout << endl;
                        if (x != -1)
                            temp.push_back(x);
                    }
                }
                else
                    break;
            }
            // else khatam hogaya
            float amt = (float)amtpayed / temp.size();
            for (auto it : temp)
            {
                exp[i][it] = amt;
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
    cout<<endl;
    for (int i = 0; i < n; i++)
    {
        int owe = tamount;
        int get = 0;
        vector<int>toget;

        if (exp[i][i] >= tamount)
        {
            owe = 0;
            for (int j = 0; j < n; j++)
            {
                if (i != j && exp[i][j]!=0)
                {
                    get += exp[i][j];
                    toget.push_back(j);
                }
            }
        }

        int toown;
        for (int j = 0; j < n; j++)
        {
            if(exp[i][j]!=0)
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
            for(auto it:toget)
            {   
                cout<<v[it]<<" Amount "<< tamount << endl;

            }   
        }
        else
        {
            cout << v[i] << " Owes " << v[toown] <<" Amount "<< tamount<< endl;
        }
        cout<<endl;
        cout<<endl;
    }
}