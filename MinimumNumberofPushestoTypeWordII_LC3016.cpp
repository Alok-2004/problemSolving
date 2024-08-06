/*
3016. Minimum Number of Pushes to Type Word II
You are given a string word containing lowercase English letters.

Telephone keypads have keys mapped with distinct collections of lowercase English letters, which can be used to form words by pushing them. 
For example, the key 2 is mapped with ["a","b","c"], we need to push the key one time to type "a", two times to type "b", and three times to type "c" .

It is allowed to remap the keys numbered 2 to 9 to distinct collections of letters. 
The keys can be remapped to any amount of letters, but each letter must be mapped to exactly one key. 
You need to find the minimum number of times the keys will be pushed to type the string word.

Return the minimum number of pushes needed to type word after remapping the keys.

An example mapping of letters to keys on a telephone keypad is given below. Note that 1, *, #, and 0 do not map to any letters.
*/
/*
class Solution {
public:
    int minimumPushes(string word) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        int res = 0;
        unordered_map<char , int>uM;
        for( char ele : word){
            uM[ele]++;
        }
        priority_queue< int >pq;
        for( pair<char , int> p : uM){
            pq.push(p.second);
        }

        int i = 0;
        while( !pq.empty() ){
                res += pq.top()* (i/8 + 1);
                cout<<pq.top() << " "<<i<<endl;
                pq.pop();
                i++;
        }

        return res;
         
    }
};
*/

class Solution {
public:
    int minimumPushes(string word) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        vector<int> temp(26, 0);
        for (char ele : word) {
            temp[ele - 'a']++;
        }
        
        sort(temp.rbegin(), temp.rend());
        
        int k = 0;
        for (int i = 0; i < 26; i++) {
            if (temp[i] == 0) break;
            k += (i / 8 + 1) * temp[i];
        }
        
        return k;
    }
};
