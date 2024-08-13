#include <bits/stdc++.h>
#include <iostream>
#include <set>
#include <queue>

using namespace std;
// O(n* word length * 26)
int main()
{
    vector<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};
    string beginWord = "hit";
    string endWord = "cog";
    set<string>st(wordList.begin(),wordList.end());
    st.erase(beginWord);
    queue<pair<string,int>>q;
    q.push({beginWord,1});
    if(st.find(endWord)==st.end())
    return 0;
    while(!q.empty())
    {
        string word = q.front().first;
        int steps = q.front().second;
        q.pop();
        if(word==endWord)
        return steps;

        
        for(int i=0;i<word.length();i++)
        {
            char origin = word[i];
            for(char c='a';c<='z';c++)
            {
                if(word[i]!=c)
                {
                    word[i] = c;
                    if(st.find(word)!=st.end()) //word exists
                    {   
                        st.erase(word);
                        q.push({word,steps+1});
                    }   
                }
            }
            word[i] = origin;
        }
    }
}