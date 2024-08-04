#include <iostream>
#include <string>

using namespace std;

string reversePrefix(string word, char ch) {
    size_t sz = word.size();
    int idx = word.find(ch);
    if (idx == -1) return word;
    else {
        int i = 0;
        while (i < idx) {
            swap(word[i], word[idx]);
            i++;
            idx--;
        }
    }

    return word;
}

int main() {
    string word = "abcdef";
    char ch = 'd';

    string result = reversePrefix(word, ch);

    cout << "After reversing prefix: " << result << endl;

    return 0;
}

