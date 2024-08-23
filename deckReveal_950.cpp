#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int sz = deck.size();
        sort(deck.begin(), deck.end());
        queue<int> q;
        vector<int> ans(sz);

        // Initialize the queue with indices
        for (int i = 0; i < sz; ++i) {
            q.push(i);
        }

        // Place the cards in the correct order
        for (int i = 0; i < sz; ++i) {
            ans[q.front()] = deck[i];
            q.pop();
            if (!q.empty()) {
                q.push(q.front());
                q.pop();
            }
        }

        return ans;
    }
};

int main(){
    
}