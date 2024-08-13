#include <bits/stdc++.h>
#include <iostream>
#include <set>
#include <queue>

using namespace std;
vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        
}
int main()
{
    vector<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};
    string beginWord = "hit";
    string endWord = "cog";

    
    set<string>st(wordList.begin(),wordList.end());
    queue<vector<string>>q;
    q.push({beginWord});

    vector<vector<string>>ans;
    while(!q.empty())
    {
        vector<string> temp = q.front();
        q.pop();
        string word = temp[temp.size()-1];

        if(word==endWord)
        ans.push_back(temp);


        for(int i=0;i<word.length();i++)
        {
            char origin = word[i];
            for(char c = 'a';c<='z';c++)
            {
                if(word[i]!=c)
                {
                    word[i] = c;
                    if(st.find(word)!=st.end()) //word exists
                    {   
                        st.erase(word);
                        temp.push_back(word);
                        q.push(temp);
                    } 
                }
            }
        }
    }
    // return ans;
}