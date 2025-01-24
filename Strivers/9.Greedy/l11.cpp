#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// valid parenthesis string
// O(3n)
bool solve(string test, int index, int count, vector<vector<int>> &dp)
{
    if (count < 0)
        return false;
    if (index == test.size())
    {
        return (count == 0);
    }

    if (dp[index][count] != -1)
        return dp[index][count];

    if (test[index] == '(')
    {
        return dp[index][count] = solve(test, index + 1, count + 1, dp);
    }
    if (test[index] == ')')
        return dp[index][count] = solve(test, index + 1, count - 1, dp);

    return dp[index][count] = solve(test, index + 1, count + 1, dp) || solve(test, index + 1, count, dp) || solve(test, index + 1, count - 1, dp);
}
bool solve2(string test)
{
    int n = test.length();
    int mini = 0, maxi = 0;
    for (int i = 0; i < n; i++)
    {
        if (test[i] == '(')
        {
            mini++;
            maxi++;
        }
        else if (test[i] == ')')
        {
            mini--;
            maxi--;
        }
        else
        {
            mini--;
            maxi++;
        }

        if (mini < 0)
        {
            mini = 0;
        }
        if (maxi < 0)
            return false;
    }
    return mini == 0;
}
int main()
{
    string test = "(**(*)";
    int n = test.size();
    // O(N2) O(N2)
    vector<vector<int>> dp(n, vector<int>(n, -1));
    // cout<<solve(test,0,0,dp);
    cout<<solve2(test);
}