#include <iostream>
#include <vector>
#include <string>

using namespace std;

string customSortString(string order, string s) {
    vector<int> freq(26, 0);
    string ans = "";

    for(int i = 0; i<s.size(); i++){
        freq[s[i] - 'a']++;
    }

    for(int i = 0; i < order.size(); i++) {
        char ch = order[i];
        while(freq[ch - 'a'] > 0){
            ans.push_back(ch);
            freq[ch - 'a']--;
        }
    }

    for (int i = 0; i < 26; i++) {
        while (freq[i] > 0) {
            ans.push_back(i + 'a');
            freq[i]--;
        }
    }

    return ans;
}

int main() {
    string order = "cba";
    string s = "abcd";
    cout << "Custom sorted string: " << customSortString(order, s) << endl;
    return 0;
}
