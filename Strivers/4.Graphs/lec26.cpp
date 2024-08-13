#include <bits/stdc++.h>
#include <iostream>
#include <set>
#include <queue>

using namespace std;



 vector<int>toposort(vector<int>adj[],int n)
    {
    vector<int> indegree(n, 0);
    for (int i = 0; i < n; i++)
    {
        for (auto it : adj[i])
        {
            adj[it].push_back(i);
            indegree[i]++;
        }
    }
    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        if (indegree[i] == 0)
            q.push(i);
    }
vector<int>visited;
    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        visited.push_back(node);
        for(auto it:adj[node])
        {
            indegree[it]--;
            if(indegree[it]==0)
            q.push(it);
        }
    }
    return visited;
    }
    string findOrder(string dict[], int n, int k) {
        vector<int>adj[k];
        for(int i=0;i<n-1;i++)
        {
            string s1 = dict[i];
            string s2 = dict[i+1];
            
            int len = min(s1.length(),s2.length());
            for(int j=0;j<len;j++)
            {
                if(s1[j]!=s2[j])
                {
                    adj[s1[j] - 'a'].push_back(s2[j]-'a');
                    break;
                }
            }
        }
        vector<int>ans = toposort(adj,k);
        string s="";
        for(auto it:ans)
        {
            s=s+char(it+'a');
        }
        return s;
    }
int main()
{
    
}