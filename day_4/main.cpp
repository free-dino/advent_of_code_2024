#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

// Function to check if a diagonal forms "MAS" or "SAM"
bool isMASorSAM(char first, char middle, char last) {
    return (first == 'M' && middle == 'A' && last == 'S') ||
           (first == 'S' && middle == 'A' && last == 'M');
}

// Function to check if an X-MAS pattern exists at the center (x, y)
bool isXMASPattern(const vector<string> &grid, int x, int y) {
    int rows = grid.size();
    int cols = grid[0].size();

    // Ensure all required positions are within bounds
    if (x - 1 < 0 || x + 1 >= rows || y - 1 < 0 || y + 1 >= cols) {
        return false;
    }

    // Check diagonals
    return isMASorSAM(grid[x - 1][y - 1], grid[x][y], grid[x + 1][y + 1]) &&
           isMASorSAM(grid[x - 1][y + 1], grid[x][y], grid[x + 1][y - 1]);
}

// Function to count all X-MAS patterns in the grid
int countXMASPatterns(const vector<string> &grid) {
    int rows = grid.size();
    int cols = grid[0].size();
    int count = 0;

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (grid[i][j] == 'A' && isXMASPattern(grid, i, j)) {
                count++;
            }
        }
    }

    return count;
}

int main() {
    ifstream file("input.txt");
    vector<string> grid;
    string line;

    // Read the grid from the file
    while (getline(file, line)) {
        grid.push_back(line);
    }

    file.close();

    // Count the X-MAS patterns
    int result = countXMASPatterns(grid);

    cout << "Total X-MAS patterns: " << result << endl;

    return 0;
}
