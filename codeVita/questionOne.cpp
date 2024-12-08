#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int main() {
    vector<int> digit_map(10);
    for (int i = 0; i < 3; ++i) {
        string line;
        cin >> line;
        for (int j = 0; j < 10; ++j) {
            digit_map[j] = (digit_map[j] << 1) | (line[j * 3] - '0');
            digit_map[j] = (digit_map[j] << 1) | (line[j * 3 + 1] - '0');
            digit_map[j] = (digit_map[j] << 1) | (line[j * 3 + 2] - '0');
        }
    }

    int n;
    cin >> n;

    vector<int> input_digits(n);
    for (int i = 0; i < 3; ++i) {
        string line;
        cin >> line;
        for (int j = 0; j < n; ++j) {
            input_digits[j] = (input_digits[j] << 1) | (line[j * 3] - '0');
            input_digits[j] = (input_digits[j] << 1) | (line[j * 3 + 1] - '0');
            input_digits[j] = (input_digits[j] << 1) | (line[j * 3 + 2] - '0');
        }
    }

    unordered_map<int, unordered_set<int>> toggle_map;
    for (int i = 0; i < 10; ++i) {
        toggle_map[digit_map[i]].insert(i);
        for (int bit = 0; bit < 9; ++bit) toggle_map[digit_map[i] ^ (1 << bit)].insert(i);
    }

    vector<vector<int>> possible_numbers(n);
    for (int i = 0; i < n; ++i) {
        if (toggle_map.find(input_digits[i]) == toggle_map.end()) {
            cout << "Invalid" << endl;
            return 0;
        }
        possible_numbers[i] = vector<int>(toggle_map[input_digits[i]].begin(), toggle_map[input_digits[i]].end());
    }

    long long total_sum = 0, multiplier = 1;
    for (int i = n - 1; i >= 0; --i) {
        long long current_sum = 0;
        for (int digit : possible_numbers[i]) current_sum += digit;
        total_sum += current_sum * multiplier;
        multiplier *= 10;
    }

    cout << total_sum << endl;
}

