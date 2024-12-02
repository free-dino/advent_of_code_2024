#include <bits/stdc++.h>
using namespace std;

bool is_increasing(const vector<int> &v) {
    for (int i = 0; i < v.size() - 1; i++) {
        if (v[i] >= v[i + 1]) {
            return false;
        }
    }
    return true;
}

// Function to check if levels are strictly decreasing
bool is_decreasing(const vector<int> &v) {
    for (int i = 0; i < v.size() - 1; ++i) {
        if (v[i] <= v[i + 1]) {
            return false; // Not decreasing
        }
    }
    return true;
}

// Function to check the difference constraint (at least 1 and at most 3)
bool check_differences(const vector<int> &v) {
    for (int i = 0; i < v.size() - 1; ++i) {
        int diff = abs(v[i] - v[i + 1]);
        if (diff < 1 || diff > 3) {
            return false; // Difference is not in the valid range
        }
    }
    return true;
}

// Function to check if a report is safe
bool is_safe(const vector<int> &v) {
    return (is_increasing(v) || is_decreasing(v)) && check_differences(v);
}

// Function to check if a report can be safe by removing one level
bool is_safe_with_dampener(const vector<int> &v) {
    if (is_safe(v)) {
        return true; // Already safe
    }
    for (int i = 0; i < v.size(); ++i) {
        // Create a new vector without the i-th level
        vector<int> temp = v;
        temp.erase(temp.begin() + i);

        // Check if the new sequence is safe
        if (is_safe(temp)) {
            return true;
        }
    }
    return false; // Cannot be made safe by removing one level
}

int main() {
    // Read the input file
    freopen("input.txt", "r", stdin);
    string line;
    int safe_count = 0, safe_with_dampener_count = 0;

    while (getline(cin, line)) {
        stringstream ss(line);
        vector<int> levels;
        int n;

        // Parse the levels from the line
        while (ss >> n) {
            levels.push_back(n);
        }

        // Task 1: Count safe reports
        if (is_safe(levels)) {
            safe_count++;
        }

        // Task 2: Count safe reports with problem dampener
        if (is_safe_with_dampener(levels)) {
            safe_with_dampener_count++;
        }
    }

    // Output the results
    cout << "Task 1: Safe reports: " << safe_count << endl;
    cout << "Task 2: Safe reports with problem dampener: " << safe_with_dampener_count << endl;

    return 0;
}
