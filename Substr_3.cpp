#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int repeating(string str) 
{
    if (str.size() <= 1)   return str.size();    
    sort(str.begin(), str.end());
    for (int i = 0; i < str.size() - 1; i++) 
    {
    if (str[i] == str[i+1])  return 0; 
    }
	return str.size();
}

int lengthOfLongestSubstring(string s) 
{
    int sze = 0;
    for (int i = 0; i < s.size(); i++) 
    {
    	for (int j = i; j < s.size(); j++)  
        {
            string str = s.substr(i, j - i + 1); 
            sze = max(sze, repeating(str));
        }
    }
    return sze;
}

int main() {
    cout << lengthOfLongestSubstring("abcabcbb") <<endl; // Expected: 3
    cout << lengthOfLongestSubstring("bbbbb") <<endl;    // Expected: 1
    cout << lengthOfLongestSubstring("pwwkew") <<endl;   // Expected: 3

    return 0;
}
