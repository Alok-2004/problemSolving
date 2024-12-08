#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
using namespace std;

struct Wire {
    int x1, y1, x2, y2;
};

int calculate_min_cells(const Wire& wire, int x, int y) {
    int min_left = INT_MAX, min_right = INT_MAX;
    if (wire.x1 == wire.x2 && wire.x1 == x) {  // Vertical wire passing through (x, y)
        min_left = abs(y - min(wire.y1, wire.y2));
        min_right = abs(y - max(wire.y1, wire.y2));
    } else if (wire.y1 == wire.y2 && wire.y1 == y) {  // Horizontal wire passing through (x, y)
        min_left = abs(x - min(wire.x1, wire.x2));
        min_right = abs(x - max(wire.x1, wire.x2));
    } else if (abs(wire.x2 - wire.x1) == abs(wire.y2 - wire.y1)) {  // Diagonal wire
        if (abs(x - wire.x1) == abs(y - wire.y1)) {
            int cells1 = min(abs(x - wire.x1), abs(y - wire.y1));
            int cells2 = min(abs(x - wire.x2), abs(y - wire.y2));
            min_left = min(cells1, cells2);
        }
    }
    return min(min_left, min_right);
}

int calculate_voltage(const vector<Wire>& wires, int x, int y) {
    int count = 0, min_cells = INT_MAX;
    for (const auto& wire : wires) {
        if ((wire.x1 == wire.x2 && wire.x1 == x && min(wire.y1, wire.y2) <= y && max(wire.y1, wire.y2) >= y) ||
            (wire.y1 == wire.y2 && wire.y1 == y && min(wire.x1, wire.x2) <= x && max(wire.x1, wire.x2) >= x) ||
            (abs(wire.x2 - wire.x1) == abs(wire.y2 - wire.y1) && abs(x - wire.x1) == abs(y - wire.y1))) {
            ++count;
            min_cells = min(min_cells, calculate_min_cells(wire, x, y));
        }
    }
    return count > 0 ? count * min_cells : 0;
}

int main() {
    int n;
    cin >> n;
    vector<Wire> wires(n);
    for (int i = 0; i < n; ++i) {
        cin >> wires[i].x1 >> wires[i].y1 >> wires[i].x2 >> wires[i].y2;
    }

    map<string, int> animalThresholds;
    string thresholds;
    cin.ignore();
    getline(cin, thresholds);
    size_t pos = 0;
    while ((pos = thresholds.find(' ')) != string::npos) {
        string pair = thresholds.substr(0, pos);
        size_t colon = pair.find(':');
        animalThresholds[pair.substr(0, colon)] = stoi(pair.substr(colon + 1));
        thresholds.erase(0, pos + 1);
    }
    size_t colon = thresholds.find(':');
    animalThresholds[thresholds.substr(0, colon)] = stoi(thresholds.substr(colon + 1));

    string testAnimal;
    cin >> testAnimal;

    int totalVoltage = 0;
    vector<pair<int, int>> intersections;
    for (int x = 0; x <= 100; ++x) {
        for (int y = 0; y <= 100; ++y) {
            int voltage = calculate_voltage(wires, x, y);
            if (voltage > 0) {
                totalVoltage += voltage;
                intersections.emplace_back(x, y);
            }
        }
    }

    int deaths = 0;
    for (const auto& [animal, threshold] : animalThresholds) {
        if (totalVoltage > threshold) {
            ++deaths;
        }
    }

    cout << (totalVoltage > animalThresholds[testAnimal] ? "Yes" : "No") << endl;
    cout << fixed << setprecision(2) << static_cast<double>(deaths) / animalThresholds.size() << endl;

    return 0;
}

