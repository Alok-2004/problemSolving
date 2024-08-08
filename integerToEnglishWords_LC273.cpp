/*
273. Integer to English Words
Convert a non-negative integer num to its English words representation.s
*/

class Solution {
public:
    void directNumber(unordered_map<char, string>& ones, unordered_map<char, string>& ties, unordered_map<char, string>& teens) {
        ones['1'] = "One";
        ones['2'] = "Two";
        ones['3'] = "Three";
        ones['4'] = "Four";
        ones['5'] = "Five";
        ones['6'] = "Six";
        ones['7'] = "Seven";
        ones['8'] = "Eight";
        ones['9'] = "Nine";

        teens['1'] = "Eleven";
        teens['2'] = "Twelve";
        teens['3'] = "Thirteen";
        teens['4'] = "Fourteen";
        teens['5'] = "Fifteen";
        teens['6'] = "Sixteen";
        teens['7'] = "Seventeen";
        teens['8'] = "Eighteen";
        teens['9'] = "Nineteen";

        ties['1'] = "Ten";
        ties['2'] = "Twenty";
        ties['3'] = "Thirty";
        ties['4'] = "Forty";
        ties['5'] = "Fifty";
        ties['6'] = "Sixty";
        ties['7'] = "Seventy";
        ties['8'] = "Eighty";
        ties['9'] = "Ninety";
    }

    string chunks(string str, unordered_map<char, string>& ones, unordered_map<char, string>& ties, unordered_map<char, string>& teens) {
        string result = "";
        int len = str.size();

        if (len == 3) {
            if (str[0] != '0') {
                result += ones[str[0]] + " Hundred ";
            }
            str = str.substr(1, 2);
            len = 2;
        }
        if (len == 2) {
            if (str[0] == '1' && str[1] != '0') {
                result += teens[str[1]] + " ";
                return result;
            } else if (str[0] != '0') {
                result += ties[str[0]] + " ";
            }
            str = str.substr(1, 1);
            len = 1;
        }
        if (len == 1 && str[0] != '0') {
            result += ones[str[0]] + " ";
        }
        return result;
    }

    string numberToWords(int num) {
        if (num == 0) return "Zero";

        string n = to_string(num);
        unordered_map<char, string> ones;
        unordered_map<char, string> ties;
        unordered_map<char, string> teens;
        directNumber(ones, ties, teens);

        unordered_map<int, string> digitCategory = {
            {3, "Hundred"},
            {4, "Thousand"},
            {5, "Thousand"},
            {6, "Thousand"},
            {7, "Million"},
            {8, "Million"},
            {9, "Million"},
            {10, "Billion"},
            {11, "Billion"},
            {12, "Billion"}
        };

        string res = "";
        int sz = n.size();
        int start = sz % 3;
        
        if(sz < 3){
            res = chunks(n , ones , ties , teens);
            if (!res.empty() && res.back() == ' ') {
                res.pop_back();
            }
            return res;
        }

        if (start != 0) {
            string sub = n.substr(0, start);
            res += chunks(sub, ones, ties, teens) + digitCategory[n.size() - start + 3] + " ";
        }

        for (int i = start; i < sz; i += 3) {
            string sub = n.substr(i, 3);
            if (stoi(sub) != 0) {
                res += chunks(sub, ones, ties, teens);
                if (digitCategory.find(sz - i) != digitCategory.end()) {
                    if( i < sz-3) res += digitCategory[sz - i] + " ";
                }
            }
        }

        if (!res.empty() && res.back() == ' ') {
            res.pop_back();
        }

        return res;
    }
};

