#pragma once

#include <iostream>
#include <vector>
#include <cmath>
#include "LRUcache.hpp"
#include "LinkedList.hpp"

using namespace std;

bool containsString(string s, string t);
string minWindow(string s, string t);
bool containsString(const string& s, vector<int>map, const string& t);
int main()
{
    vector<int> nums1 = { 1,2,5, 3,9,10,1 };
    vector<int> nums2 = { 2,5,6 };
    vector<vector<int>> dungeon = { {0, 0, 0}, {1, 1, -1}};
    int m = 3;
    int n = 3;
    string s = "a";
    string t = "a";
    ListNode* head = makeList(10);
    head = reverse(head);
    head = mergeSortLinkedList(head);
    LRUCache lRUCache(3);
    //lRUCache.put(1, 1); // cache is {1=1}
    //lRUCache.put(2, 2); // cache is {1=1, 2=1}
    //lRUCache.put(3, 3); // cache is {2=3, 1=1}
    //lRUCache.put(4, 4); // cache is {4=1, 2=3}
    //lRUCache.get(4);    // return -1 (not found)
    //lRUCache.get(3);    // return 3
    //lRUCache.get(2);    // return -1 (not found)
    //lRUCache.get(1);    // return 3
    //lRUCache.put(5, 5); // cache is {4=1, 2=3}
    //lRUCache.get(1);    // return -1 (not found)
    //lRUCache.get(2);    // return 3
    //lRUCache.get(3);    // return -1 (not found)
    //lRUCache.get(4);    // return 3
    //lRUCache.get(5);    // return 3

}

string minWindow(string s, string t) {
    int size = s.size();
    int start = 0, end = 0;
    string result = "";
    int minStart = INT_MAX, minLen = INT_MAX;
    if (t.size() > s.size())
        return result;
    string temp = s;
    // first, try to get the window that contains t
    while (end < s.size())
    {
        ++end;
        temp = s.substr(start, end - start);
        if (containsString(temp, t) == true)
        {
            // if found, try minimize it
            for (; start < end; start++)
            {
                string temp = s.substr(start, end - start);
                if (containsString(temp, t) != true)
                    break;
            }
            --start;
            if (end - start < minLen)
            {
                minStart = start;
                minLen = end - start;
            }
        }
    }
    if (start < 0 || minLen == INT_MAX)
        return "";
    return s.substr(minStart, minLen);
}

bool containsString(string s, string t)
{
    for (int i = 0; i < t.size(); ++i)
    {
        size_t pos = s.find(t[i]);
        if (pos != string::npos)
            s = s.erase(pos, 1);
        else
            return false;
    }
    return true;
}

bool containsString(const string& s, vector<int>map, const string& t)
{
    for (int i = 0; i < s.size(); ++i)
    {
        map[s[i]]--;
    }
    for (int i = 0; i < t.size(); ++i)
    {
        if (map[t[i]] > 0)
            return false;
    }
    return true;
}


int calculateMinimumHP(vector<vector<int>>& dungeon) {
    int yLimit = dungeon[0].size();
    int xLimit = dungeon.size();
    int x = xLimit - 1, y = yLimit - 1;

    vector<vector<int>> healthMap(xLimit + 1, vector<int>(yLimit + 1, INT_MAX));
    healthMap[x][y] = dungeon[x][y] >= 0 ? 1 : -(dungeon[x][y]) + 1;
    // need abs of negative value at the x,y + 1 to survive, or 1 hp if positive value
    for (; x >= 0; x--)
    {
        for (int y = yLimit - 1; y >= 0; y--)
        {
            int health = dungeon[x][y];
            if (x == xLimit - 1 && y == yLimit - 1)
            {
            }
            else
            {
                int prev = healthMap[x + 1][y] < healthMap[x][y + 1] ?
                    healthMap[x + 1][y] :
                    healthMap[x][y + 1];

                health = prev - health;

                if (health <= 0)
                    health = 1;
                healthMap[x][y] = min(healthMap[x][y], health);
            }
        }

    }
    if (healthMap[0][0] < 0)
        return 1;
    return healthMap[0][0];
}

string minWindow(string s, string t) {
    unordered_map<char, int> m;
    // Statistic for count of char in t
    for (auto c : t) m[c]++;
    // counter represents the number of chars of t to be found in s.
    size_t start = 0, end = 0, counter = t.size(), minStart = 0, minLen = INT_MAX;
    size_t size = s.size();

    // Move end to find a valid window.
    while (end < size) {
        // If char in s exists in t, decrease counter
        if (m[s[end]] > 0)
            counter--;
        // Decrease m[s[end]]. If char does not exist in t, m[s[end]] will be negative.
        m[s[end]]--;
        end++;
        // When we found a valid window, move start to find smaller window.
        while (counter == 0) {
            if (end - start < minLen) {
                minStart = start;
                minLen = end - start;
            }
            m[s[start]]++;
            // When char exists in t, increase counter.
            if (m[s[start]] > 0)
                counter++;
            start++;
        }
    }
    if (minLen != INT_MAX)
        return s.substr(minStart, minLen);
    return "";
}