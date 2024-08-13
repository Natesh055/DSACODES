#include <iostream>
#include <unordered_map>
#include <set>
#include <vector>
#include <map>
using namespace std;
int main()
{
    vector<int> arr = {1, 1, 2};
    map<int, bool> mp;
    for (int i = 0; i < arr.size(); i++)
    {
        mp[arr[i]] = true;
    }
    arr.resize(mp.size());
    int index = 0;
    for (auto it:mp)
    {
        arr[index++] = it.first;
    }
    return mp.size();
}